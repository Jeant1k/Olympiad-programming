#include <regex>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

enum class State {
    LETTER,
    SPACE,
    BACKSLASHN1,
    IMAGE,
    BACKSLASHN2
};

int main() {

    ifstream file("input.txt");

    int w, h, c;
    file >> w >> h >> c;

    string line;
    getline(file, line);

    regex layout_regex("layout=(\\w+)");
    regex width_regex("width=(\\d+)");
    regex height_regex("height=(\\d+)");
    regex dx_regex("dx=(-?\\d+)");
    regex dy_regex("dy=(-?\\d+)");
    smatch matches;

    char ch;
    State state = State::LETTER;
    int x = 0, y = 0;
    int cur_h = h;
    while (file.get(ch)) {
        if (state == State::LETTER && ch == ' ') {
            state = State::SPACE;
        } else if (state == State::LETTER && ch == '\n') {
            state = State::BACKSLASHN1;
        } else if (state == State::LETTER && ch == '(') {
            state = State::IMAGE;
            getline(file, line, ')');
            file.putback(')');
            string layout = "";
            int width = -1, height = -1, dx = 10000, dy = 10000;
            if (regex_search(line, matches, layout_regex)) layout = matches[1];
            if (regex_search(line, matches, width_regex)) width = stoi(matches[1]);
            if (regex_search(line, matches, height_regex)) height = stoi(matches[1]);
            if (regex_search(line, matches, dx_regex)) dx = stoi(matches[1]);
            if (regex_search(line, matches, dy_regex)) dy = stoi(matches[1]);
            if (layout == "embedded") {
                if (x + width > w) {
                    y += cur_h;
                    cur_h = h;
                    x = width;
                } else {
                    x += width;
                }
                cur_h = max(height, h);
            }
        } else if (state == State::LETTER) {
            x += c;
            if (x > w) {
                x = c;
                y += cur_h;
                cur_h = h;
            }
        } else if (state == State::SPACE && ch == '(') {
            state = State::IMAGE;
            getline(file, line, ')');
            file.putback(')');
            string layout = "";
            int width = -1, height = -1, dx = 10000, dy = 10000;
            if (regex_search(line, matches, layout_regex)) layout = matches[1];
            if (regex_search(line, matches, width_regex)) width = stoi(matches[1]);
            if (regex_search(line, matches, height_regex)) height = stoi(matches[1]);
            if (regex_search(line, matches, dx_regex)) dx = stoi(matches[1]);
            if (regex_search(line, matches, dy_regex)) dy = stoi(matches[1]);
            if (layout == "embedded") {
                if (x + c + width > w) {
                    y += cur_h;
                    cur_h = h;
                    x = width;
                } else {
                    x += (c + width);
                }
                cur_h = max(height, h);
            }
        } else if (state == State::SPACE) {
            state = State::LETTER;
            x += (2 * c);
            if (x > w) {
                x = c;
                y += cur_h;
                cur_h = h;
            }
        } else if (state == State::BACKSLASHN1 && ch == '\n') {
            state = State::BACKSLASHN2;
        } else if (state == State::BACKSLASHN1 && ch == '(') {
            state = State::IMAGE;
            getline(file, line, ')');
            file.putback(')');
            string layout = "";
            int width = -1, height = -1, dx = 10000, dy = 10000;
            if (regex_search(line, matches, layout_regex)) layout = matches[1];
            if (regex_search(line, matches, width_regex)) width = stoi(matches[1]);
            if (regex_search(line, matches, height_regex)) height = stoi(matches[1]);
            if (regex_search(line, matches, dx_regex)) dx = stoi(matches[1]);
            if (regex_search(line, matches, dy_regex)) dy = stoi(matches[1]);
            if (layout == "embedded") {
                if (x + c + width > w) {
                    y += cur_h;
                    cur_h = h;
                    x = width;
                } else {
                    x += (c + width);
                }
                cur_h = max(height, h);
            }
        } else if (state == State::BACKSLASHN1) {
            state = State::LETTER;
            x += (2 * c);
            if (x > w) {
                x = c;
                y += cur_h;
                cur_h = h;
            }
        } else if (state == State::IMAGE) {
            state = State::LETTER;
        } else if (state == State::BACKSLASHN2 && ch == '(') {
            state = State::IMAGE;
            getline(file, line, ')');
            file.putback(')');
            string layout = "";
            int width = -1, height = -1, dx = 10000, dy = 10000;
            if (regex_search(line, matches, layout_regex)) layout = matches[1];
            if (regex_search(line, matches, width_regex)) width = stoi(matches[1]);
            if (regex_search(line, matches, height_regex)) height = stoi(matches[1]);
            if (regex_search(line, matches, dx_regex)) dx = stoi(matches[1]);
            if (regex_search(line, matches, dy_regex)) dy = stoi(matches[1]);
            if (layout == "embedded") {
                if (x + width > w) {
                    y += cur_h;
                    cur_h = h;
                    x = width;
                } else {
                    x += width;
                }
                cur_h = max(height, h);
            }
        } else if (state == State::BACKSLASHN2) {
            state = State::LETTER;
            x = c;
            y += cur_h;
            cur_h = h;
        }
        cout << "x = " << x << " y = " << y << " c = " << ch << endl;
    }



    // line = "";
    // int x = 0, y = 0;
    // int cur_h = h;
    // while (file.get(ch)) {
    //     if (ch == '\n') {
    //         file.get(ch);
    //         if (ch == '\n') {
    //             x = 0;
    //             y += cur_h;
    //         } else {
    //             x += c;
    //             if (x > w) {
    //                 x = c;
    //                 y += cur_h;
    //             }
    //         }
    //     }
    //     if (ch == '(') {
    //         is_image = true;
    //     } else if (ch == ')') {
    //         is_image = false;
            // string layout = "";
            // int width = 0, height = 0, dx = 0, dy = 0;
            // if (regex_search(line, matches, layout_regex)) layout = matches[1];
            // if (regex_search(line, matches, width_regex)) width = stoi(matches[1]);
            // if (regex_search(line, matches, height_regex)) height = stoi(matches[1]);
            // if (regex_search(line, matches, dx_regex)) dx = stoi(matches[1]);
            // if (regex_search(line, matches, dy_regex)) dy = stoi(matches[1]);
            
    //         line = "";
    //     } else if (is_image) {
    //         line += ch;
    //     } else {
    //         x += c;
    //         if (x > w) {
    //             x = c;
    //             y += cur_h;
    //         }
    //     }
    //     cout << "x = " << x << " y = " << y << endl;
    // }

    // cout << x << endl;

    file.close();

    return 0;
    
}
