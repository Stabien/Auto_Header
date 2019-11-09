#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QFileDialog>
#include <QComboBox>
#include <QLabel>
#include <fstream>
#include <string>
#include <iostream>
#include "main_window.h"

using namespace std;

void mainWindow::c_generation()
{
    string convert_path_folder = m_name_folder->text().toUtf8().constData();
    string convert_name_file = m_name->text().toUtf8().constData();
    string complete_file_path;

    convert_path_folder.append("/");
    convert_path_folder.append(convert_name_file);
    complete_file_path = convert_path_folder.append(".c");

    ofstream my_file(complete_file_path.c_str());

    if (my_file) {
        my_file << "#include <stdio.h>\n#include <stdlib.h>" << "\n" << endl;
        my_file << "int main(int argc, char* argv[])\n{\n    return (0);\n}";
    }
}

void mainWindow::cpp_generation()
{
    string convert_path_folder = m_name_folder->text().toUtf8().constData();
    string convert_name_file = m_name->text().toUtf8().constData();
    string complete_file_path;

    convert_path_folder.append("/");
    convert_path_folder.append(convert_name_file);
    complete_file_path = convert_path_folder.append(".cpp");

    ofstream my_file(complete_file_path.c_str());

    if (my_file) {
        my_file << "#include <iostream>\n#include <string>" << "\n" << endl;
        my_file << "int main(int argc, char* argv[])\n{\n    return (0);\n}";
    }
}

void mainWindow::html_generation()
{
    string convert_path_folder = m_name_folder->text().toUtf8().constData();
    string convert_name_file = m_name->text().toUtf8().constData();
    string complete_file_path;

    convert_path_folder.append("/");
    convert_path_folder.append(convert_name_file);
    complete_file_path = convert_path_folder.append(".html");

    ofstream my_file(complete_file_path.c_str());

    if (my_file) {
        my_file << "<!DOCTYPE html>\n<html>\n<head>" << endl;
        my_file << "    <meta charset=\"utf-8\"/>" << endl;
        my_file << "    <link rel=\"stylesheet\" href=\"style.css\"/>" << endl;
        my_file << "    <title>Template</title>" << endl;
        my_file << "</head>\n\n<body>\n\n</body>\n</html>";
    }
}

void mainWindow::java_generation()
{
    string convert_path_folder = m_name_folder->text().toUtf8().constData();
    string convert_name_file = m_name->text().toUtf8().constData();
    string complete_file_path;

    convert_path_folder.append("/");
    convert_path_folder.append(convert_name_file);
    complete_file_path = convert_path_folder.append(".java");

    ofstream my_file(complete_file_path.c_str());

    if (my_file) {
        my_file << "\npublic class " << convert_name_file << " {\n" << endl;
        my_file << "    public static void main(String[] args) {\n" << endl;
        my_file << "    }\n}";
    }
}

void mainWindow::python_generation()
{
    string convert_path_folder = m_name_folder->text().toUtf8().constData();
    string convert_name_file = m_name->text().toUtf8().constData();
    string complete_file_path;

    convert_path_folder.append("/");
    convert_path_folder.append(convert_name_file);
    complete_file_path = convert_path_folder.append(".py");

    ofstream my_file(complete_file_path.c_str());

    if(my_file)
        my_file << "#!/usr/bin/python3.7\n#-*-coding:Utf-8 -*";
}

void mainWindow::call_generation()
{
    QString language_selection = m_language->currentText().toUtf8().constData();

    if (language_selection == "C")
        mainWindow::c_generation();
    if (language_selection == "C++")
        mainWindow::cpp_generation();
    if (language_selection == "Html")
        mainWindow::html_generation();
    if (language_selection == "Java")
        mainWindow::java_generation();
    if (language_selection == "Python")
        mainWindow::python_generation();
}
