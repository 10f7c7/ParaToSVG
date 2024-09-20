#include <bits/stdc++.h>
#include <string>

using namespace std;

void writeToSVG(vector<vector<float>> coords, float foci) {

    ofstream SVG("output.svg");
    SVG << "<svg viewBox='-530 -10 1060 " << foci * 1.25 << "' xmlns='http://www.w3.org/2000/svg' transform='matrix(1, 0, 0, -1, 0, 0)'>" << endl;
    cout << coords.size() << endl;
    for (int i = 0; i < coords.size()-1; i++) {
        int c = i + 1;
        if (c > coords.size()) {
            c = 0;
        }
        SVG << "<line x1='" << coords[i][0] << "' y1='" << coords[i][1] << "' x2='" << coords[c][0] << "' y2='" << coords[c][1] << "' stroke='black' stroke-width='2.52'/>" << endl;
    }
    SVG << "<line  x1='0' y1='0' x2='0' y2='" << foci << "' stroke='red' stroke-width='2.52'/>" << endl;
    SVG << "</svg>" << endl;
    SVG.close();
    return;
}

int main(int argc, char* argv[]) {
    string ParaDia = argv[1];

    std::ifstream ParaDiaFile(ParaDia);

    vector<vector<float>> coords;
    float foci;

    if (ParaDiaFile.is_open()) {
        std::string line;
        int lineCount = -9;

        while (std::getline(ParaDiaFile, line, '\n')) {
            lineCount++;
            if (lineCount > 1000)  {
                lineCount--;
                break;
            } else if(lineCount == -5) {
                foci = stof(line.replace(0, 12, ""));
                cout << foci << endl;
            } else if (lineCount >= 0) {
                line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
                line.replace(line.find("y"), 1, ",");
                line.replace(line.find("x"), 1, "");   
                float x = stof(line.substr(0, line.find(',')));
                float y = stof(line.substr(line.find(',') + 1, line.find(',')));
                coords.push_back({x, y});
                // cout << x << "," << y << endl;
                // cout << line << endl;
            }
        }
        ParaDiaFile.close();

        std::cout << "Number of lines in the file: " << lineCount << std::endl;
    }
    else {
        std::cout << "Failed to open the file." << std::endl;
    }

    writeToSVG(coords, foci);
    // for (int i = 0; i < coords.size(); i++)
    // {
    //     for (int j = 0; j < coords[i].size(); j++)
    //     {
    //         cout << coords[i][j] << ",";
    //     }
    //     cout << endl;
    // }

    return 0;
}