#include <iostream>     	// for cout, cin
#include <fstream>      	// for ifstream
#include <sstream>      	// for stringstream
#include <filesystem>   	// making inputting files easier
#include <unordered_set>	// containers for the wikiscraper
#include <vector>
#include <queue>
#include <unordered_map>
#include "wikiscraper.h"    // wikiscraper methods

using std::cout;            using std::endl;
using std::ifstream;        using std::stringstream;
using std::string;          using std::vector;
using std::priority_queue;  using std::unordered_map;
using std::unordered_set;   using std::cin;
using std::cerr;

int main() {
    // a quick working directory fix to allow for easier filename inputs
    auto path = std::filesystem::current_path() / "res/";
    std::filesystem::current_path(path);
    std::string filenames = "Available input files: ";
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string filename = entry.path().string();
        filename = filename.substr(filename.rfind("/") + 1);
        filenames += filename + ", ";
    }
    // omit last ", ".
    cout << filenames.substr(0, filenames.size() - 2) << "." << endl;

    /* Container to store the found ladders in */
    vector<vector<string>> outputLadders;

    cout << "Enter a file name: ";
    string filename;
    getline(cin, filename);

    /* 
        TODO: Create a filestream from the filename.
        For each pair {start_page, end_page} in the input file,
        retrieve the result of findWikiLadder(start_page, end_page)
        and append that vector to outputLadders.
    */
    // Write code here
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cerr << "File " << filename << " doesn't exist!" << endl;
        return -1;
    }

    int pairs;
    file >> pairs;
    for(int i = 0; i < pairs; ++i) {
        string start_page, end_page;
        file >> start_page >> end_page;
        auto result = findWikiLadder(start_page, end_page);
        outputLadders.push_back(result);
    }

    /*
     * Print out all ladders in outputLadders.
     * We've already implemented this for you!
     */
    // Write code here
    for(auto result : outputLadders) {
        int length = result.size();
        cout << result[0];
        for (int i = 1; i < length; ++i)
            cout << " -> " << result[i];
        cout << endl;
    }

    return 0;
}




