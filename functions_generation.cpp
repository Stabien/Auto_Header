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
#include <QMessageBox>
#include "main_window.h"

using namespace std;

void mainWindow::c_generation()
{
    string convert_path_folder = m_name_folder->text().toUtf8().constData();
    string convert_name_file = m_name->text().toUtf8().constData();
    string complete_file_path;
    int answer = 0;

    convert_path_folder.append("/");
    convert_path_folder.append(convert_name_file);
    complete_file_path = convert_path_folder.append(".c");

    ifstream test_my_file(complete_file_path.c_str());

    if(test_my_file)
        answer = QMessageBox::question(this, "", "this file already exist, if you continue it will be crushed, do you want to continue ? ", QMessageBox::Yes | QMessageBox::No);

    ofstream my_file(complete_file_path.c_str());

    if (my_file && answer != QMessageBox::No) {
        my_file << "#include <stdio.h>\n#include <stdlib.h>" << "\n" << endl;
        my_file << "int main(int argc, char* argv[])\n{\n    return (0);\n}";
        QMessageBox::information(this, "", "Successful Generation !");
    }
    else if (answer != QMessageBox::No)
        QMessageBox::critical(this, "", "Error: The path of the folder doesn't exist");
}

void mainWindow::cpp_generation()
{
    string convert_path_folder = m_name_folder->text().toUtf8().constData();
    string convert_name_file = m_name->text().toUtf8().constData();
    string complete_file_path;
    int answer = 0;

    convert_path_folder.append("/");
    convert_path_folder.append(convert_name_file);
    complete_file_path = convert_path_folder.append(".cpp");

    ifstream test_my_file(complete_file_path.c_str());

    if(test_my_file)
        answer = QMessageBox::question(this, "", "this file already exist, if you continue it will be crushed, do you want to continue ? ", QMessageBox::Yes | QMessageBox::No);

    ofstream my_file(complete_file_path.c_str());

    if (my_file && answer != QMessageBox::No) {
        my_file << "#include <iostream>\n#include <string>" << "\n" << endl;
        my_file << "int main(int argc, char* argv[])\n{\n    return (0);\n}";
        QMessageBox::information(this, "", "Successful Generation !");
    }
    else if (answer != QMessageBox::No)
        QMessageBox::critical(this, "", "Error: The path of the folder doesn't exist");
}

void mainWindow::html_generation()
{
    string convert_path_folder = m_name_folder->text().toUtf8().constData();
    string convert_name_file = m_name->text().toUtf8().constData();
    string complete_file_path;
    int answer = 0;

    convert_path_folder.append("/");
    convert_path_folder.append(convert_name_file);
    complete_file_path = convert_path_folder.append(".html");

    ifstream test_my_file(complete_file_path.c_str());

    if(test_my_file)
        answer = QMessageBox::question(this, "", "this file already exist, if you continue it will be crushed, do you want to continue ? ", QMessageBox::Yes | QMessageBox::No);

    ofstream my_file(complete_file_path.c_str());

    if (my_file && answer != QMessageBox::No) {
        my_file << "<!DOCTYPE html>\n<html>\n<head>" << endl;
        my_file << "    <meta charset=\"utf-8\"/>" << endl;
        my_file << "    <link rel=\"stylesheet\" href=\"style.css\"/>" << endl;
        my_file << "    <title>Template</title>" << endl;
        my_file << "</head>\n\n<body>\n\n</body>\n</html>";
        QMessageBox::information(this, "", "Successful Generation !");
    }
    else if (answer != QMessageBox::No)
        QMessageBox::critical(this, "", "Error: The path of the folder doesn't exist");
}

void mainWindow::java_generation()
{
    string convert_path_folder = m_name_folder->text().toUtf8().constData();
    string convert_name_file = m_name->text().toUtf8().constData();
    string complete_file_path;
    int answer = 0;

    convert_path_folder.append("/");
    convert_path_folder.append(convert_name_file);
    complete_file_path = convert_path_folder.append(".java");

    ifstream test_my_file(complete_file_path.c_str());

    if(test_my_file)
        answer = QMessageBox::question(this, "", "this file already exist, if you continue it will be crushed, do you want to continue ? ", QMessageBox::Yes | QMessageBox::No);

    ofstream my_file(complete_file_path.c_str());

    if (my_file && answer != QMessageBox::No ) {
        my_file << "\npublic class " << convert_name_file << " {\n" << endl;
        my_file << "    public static void main(String[] args) {\n" << endl;
        my_file << "    }\n}";
        QMessageBox::information(this, "", "Successful Generation !");
    }
    else if (answer != QMessageBox::No)
        QMessageBox::critical(this, "", "Error: The path of the folder doesn't exist");
}

void mainWindow::python_generation()
{
    string convert_path_folder = m_name_folder->text().toUtf8().constData();
    string convert_name_file = m_name->text().toUtf8().constData();
    string complete_file_path;
    int answer = 0;

    convert_path_folder.append("/");
    convert_path_folder.append(convert_name_file);
    complete_file_path = convert_path_folder.append(".py");

    ifstream test_my_file(complete_file_path.c_str());

    if(test_my_file)
        answer = QMessageBox::question(this, "", "this file already exist, if you continue it will be crushed, do you want to continue ? ", QMessageBox::Yes | QMessageBox::No);

    ofstream my_file(complete_file_path.c_str());

    if(my_file && answer != QMessageBox::No) {
        my_file << "#!/usr/bin/python3.7\n#-*-coding:Utf-8 -*";
        QMessageBox::information(this, "", "Successful Generation !");
    }
    else if(answer != QMessageBox::No)
        QMessageBox::critical(this, "", "Error: The path of the folder doesn't exist");
}

void mainWindow::call_generation()
{
    string language_selection = m_language->currentText().toUtf8().constData();

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
