#include <iostream>
#include <deque>
#include <list>
#include <typeinfo>
#include <vector>
using namespace std;

template<typename Iterator>
void iter_type(Iterator it) {
    cout << typeid(it).name() << endl;
}

int main() {
    int a[] = {1,2,3,4,5};      iter_type(begin(a));
    deque<int> d{1,2,3,4,5};    iter_type(begin(d));
    list<int> l{1,2,3,4,5};     iter_type(begin(l));
    vector<int> v{1,2,3,4,5};   iter_type(begin(v));
}

/* Output - clang:
Pi
NSt3__116__deque_iteratorIiPiRiPS1_lLl1024EEE
NSt3__115__list_iteratorIiPvEE
NSt3__111__wrap_iterIPiEE
*/

/* Output - MinGW:
Pi
St15_Deque_iteratorIiRiPiE
St14_List_iteratorIiE
N9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEE
*/

/* Output - Visual Studio:
int *
class std::_Deque_iterator<class std::_Deque_val<struct std::_Deque_simple_types<int> > >
class std::_List_iterator<class std::_List_val<struct std::_List_simple_types<int>>>
class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<int>>>
*/
