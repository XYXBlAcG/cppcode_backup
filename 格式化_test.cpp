#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <stack>

bool isOperator(const std::string& op) {
    std::vector<std::string> operators = {"+", "-", "*", "/", "%", "=", ">", "<", "&", "|", "^", "&&", "||", "<<", ">>", "?", ":"};
    return std::find(operators.begin(), operators.end(), op) != operators.end();
}

std::string formatCode(const std::string& input) {
    std::stringstream output;
    bool inString = false;
    bool inComment = false;
    bool operatorSpace = false;
    std::string currentOperator;
    int indentLevel = 0;
    bool newLine = true;
    std::stack<int> braceIndent;

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];

        if (c == '"') {
            inString = !inString;
            output << c;
        } else if (!inString) {
            if (c == '/' && i + 1 < input.size() && input[i + 1] == '/') {
                inComment = true;
                output << c;
            } else if (c == '\n' && inComment) {
                inComment = false;
                output << c;
            } else if (!inComment) {
                std::string peekTwo = input.substr(i, 2);
                std::string peekThree = input.substr(i, 3);

                if (isOperator(peekThree)) {
                    currentOperator = peekThree;
                    i += 2;
                } else if (isOperator(peekTwo)) {
                    currentOperator = peekTwo;
                    ++i;
                } else if (isOperator(std::string(1, c))) {
                    currentOperator = std::string(1, c);
                } else {
                    currentOperator.clear();
                }

                if (!currentOperator.empty()) {
                    if (!operatorSpace && !newLine) {
                        output << ' ';
                    }
                    output << currentOperator;
                    operatorSpace = true;
                } else {
                    if (operatorSpace) {
                        output << ' ';
                        operatorSpace = false;
                    }
                    output << c;

                    if (c == ';') {
                        output << '\n';
                        newLine = true;
                    } else if (c == '{') {
                        output << '\n';
                        braceIndent.push(indentLevel);
                        ++indentLevel;
                        newLine = true;
                    } else if (c == '}') {
                        output << '\n';
                        if (!braceIndent.empty()) {
                            indentLevel = braceIndent.top();
                            braceIndent.pop();
                        }
                        newLine = true;
                    } else if (c == '\n') {
                        newLine = true;
                    }
                }
            }
        } else {
            output << c;
        }

        if (newLine) {
            output << std::string(4 * indentLevel, ' ');
            newLine = false;
        }
    }

    return output.str();
}

int main() {
    std::string input, line;
    while (std::getline(std::cin, line)) {
        if (line == "end") {
            break;
        }
        input += line + '\n';
    }
    std::string formattedCode = formatCode(input);
    std::cout << "Formatted code:\n" << formattedCode << "\n";

    return 0;
}
