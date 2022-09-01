#include <filesystem>
#include <iostream>
#include <string>
using namespace std;

int main() {
	for (const auto& entry: filesystem::directory_iterator(".")) {
        auto path = entry.path();
		if (is_regular_file(entry) && path.extension() == ".dat") {
			auto fsize = entry.file_size(); 
            auto fname = path.filename().string();
			cout << fname << " (" << fsize << ")\n";
		}
	}
}