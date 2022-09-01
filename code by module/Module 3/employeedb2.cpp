// employeedb.cpp: Reads employee data into a fixed-length record file
//
// Note use of binary file mode (required on Windows; ignored on *NIX)

#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

class Employee {
    int objid;
    string ename;
    string job;
    int mgrid;
    string hiredate;
    int salary;
    int deptid;
    Employee() {
        objid = -1;
    }
    struct emprec {     // Used for file transfer
        int objid;
        char ename[11];
        char job[10];
        int mgrid;
        char hiredate[10];
        int salary;
        int deptid;
    };
    static void stobuf(const string& s, char* buf, size_t limit) {
        // Compute the numbers of chars to transfer (can't exceed limit-1)
        size_t nchars{min(limit-1,s.size())};
        
        // Copy and null-terminate
        s.copy(buf,nchars);
        buf[nchars] = '\0';
    }
    
public:
    Employee(int objid, const string& ename, const string& job, int mgrid, 
             const string& hiredate, int salary, int deptid)
             : ename(ename), job(job), hiredate(hiredate) {
        this->objid = objid;
        this->mgrid = mgrid;
        this->salary = salary;
        this->deptid = deptid;
    }
    friend ostream& operator<<(ostream& os, const Employee& e) {
        return os << '{' << e.objid << ',' << e.ename << ',' << e.job << ','
           << e.mgrid << ',' << e.hiredate << ',' << e.salary << ',' << e.deptid << '}';
    }
    void write(ostream& os) {
        emprec outbuf;
        outbuf.objid = objid;
        stobuf(ename, outbuf.ename, sizeof(outbuf.ename)-1);
        stobuf(job, outbuf.job, sizeof(outbuf.job)-1);
        outbuf.mgrid = mgrid;
        stobuf(hiredate, outbuf.hiredate, sizeof(outbuf.hiredate)-1);
        outbuf.salary = salary;
        outbuf.deptid = deptid;
        os.write(reinterpret_cast<const char*>(&outbuf), sizeof outbuf);
    }
    static Employee read(istream& is) {
        emprec inbuf;
        is.read(reinterpret_cast<char*>(&inbuf), sizeof inbuf);
        Employee emp;
        if (is) {
            emp.objid = inbuf.objid;
            emp.ename = inbuf.ename;
            emp.job = inbuf.job;
            emp.mgrid = inbuf.mgrid;
            emp.hiredate = inbuf.hiredate;
            emp.salary = inbuf.salary;
            emp.deptid = inbuf.deptid;
        }
        return emp;
    }
    bool isValid() const {
        return objid != -1;
    }
    void setJob(const string& s) {
        job = s;
    }
    static int recSize() {
        return sizeof(emprec);
    }
};

int main() {
    ifstream f("employee.db");
    if (f) {
        string line;
        // Skip first two lines;
        f.ignore(numeric_limits<streamsize>::max(), '\n');
        f.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Read/write records
        ofstream empdat("employee.rec", ios::out | ios::binary | ios::trunc);
        while (getline(f, line)) {
            int objid, mgrid, salary, deptid;
            string ename, job, hiredate;
            
            // Parse line
            istringstream linestrm(line);
            linestrm >> objid >> ename >> job >> mgrid >> hiredate >> salary >> deptid;
            
            // Write to file
            Employee emp(objid,ename,job,mgrid,hiredate,salary,deptid);
            emp.write(empdat);
        }
        empdat.close();

        // Read records
        fstream emprecs("employee.rec", ios::in | ios::out | ios::binary);
        Employee emp = Employee::read(emprecs);
        while (emp.isValid()) {
            cout << emp << endl;
            emp = Employee::read(emprecs);
        }
        cout << endl;
        
        // Move around in file
        emprecs.clear();                        // Clear EOF from previous read loop
        emprecs.seekg(0,ios::beg);              // Rewind
        emp = Employee::read(emprecs);
        cout << "record 0: " << emp << endl;
        auto pos = emprecs.tellg();             // Save position [1] for later
        
        // Overwrite first record
        emp.setJob("Bottle Washer");
        emprecs.seekp(0,ios::beg);              // Position for write
        emp.write(emprecs);
        
        // Verify change
        emprecs.seekg(0,ios::beg);              // Position for read
        emp = Employee::read(emprecs);
        cout << "record 0 again: " << emp << endl;

        // Read the third record
        emprecs.seekg(Employee::recSize(), ios::cur);   // Skip next record ([1])
        emp = Employee::read(emprecs);
        cout << "record 2: " << emp << endl;

        // Read the second record
        emprecs.seekg(pos);
        emp = Employee::read(emprecs);
        cout << "record 1: " << emp << endl;
        
        // Read last record
        emprecs.seekg(-Employee::recSize(),ios::end);
        emp = Employee::read(emprecs);
        cout << "last record: " << emp << endl;
    }
}

/* Output:
{7369,SMITH,CLERK,7902,17-DEC-80,800,20}
{7499,ALLEN,SALESMAN,7698,20-FEB-81,1600,30}
{7521,WARD,SALESMAN,7698,22-FEB-81,1250,30}
{7566,JONES,MANAGER,7839,02-APR-81,2975,20}
{7654,MARTIN,SALESMAN,7698,28-SEP-81,1250,30}
{7698,BLAKE,MANAGER,7839,01-MAY-81,2850,30}
{7782,CLARK,MANAGER,7839,09-JUN-81,2450,10}
{7788,SCOTT,ANALYST,7566,09-DEC-82,3000,20}
{7839,KING,PRESIDENT,0,17-NOV-81,5000,10}
{7844,TURNER,SALESMAN,7698,08-SEP-81,1500,30}
{7876,ADAMS,CLERK,7788,12-JAN-83,1100,20}
{7900,JAMES,CLERK,7698,03-DEC-81,950,30}
{7902,FORD,ANALYST,7566,03-DEC-81,3000,20}
{7934,MILLER,CLERK,7782,23-JAN-82,1300,10}

record 0: {7369,SMITH,CLERK,7902,17-DEC-80,800,20}
record 0 again: {7369,SMITH,Bottle Wa,7902,17-DEC-80,800,20}
record 2: {7521,WARD,SALESMAN,7698,22-FEB-81,1250,30}
record 1: {7499,ALLEN,SALESMAN,7698,20-FEB-81,1600,30}
last record: {7934,MILLER,CLERK,7782,23-JAN-82,1300,10}
*/