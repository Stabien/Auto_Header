#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QFileDialog>
#include <QComboBox>
#include <QLabel>
#include <QTextEdit>
#include <fstream>
#include <string>
#include <iostream>
#include "main_window.h"

using namespace std;

mainWindow::mainWindow() : QWidget()
{
    m_main_layout = new QFormLayout;
    m_hbox_path_file = new QHBoxLayout;
    m_main_group = new QGroupBox;
    m_language = new QComboBox;
    m_name = new QLineEdit;
    m_name_folder = new QLineEdit;
    m_button_path_file = new QPushButton("...");
    m_bottom_buttons_layout = new QHBoxLayout;
    m_generate = new QPushButton("Generate");
    m_leave = new QPushButton("Leave");

    setWindowTitle ("File Template");
    resize(500, 210);
    
    m_language->addItem("C");
    m_language->addItem("C++");
    m_language->addItem("Html");
    m_language->addItem("Java");
    m_language->addItem("Python");

    m_hbox_path_file->addWidget(m_name_folder);
    m_hbox_path_file->addWidget(m_button_path_file);

    m_bottom_buttons_layout->setAlignment(Qt::AlignRight);
    m_bottom_buttons_layout->addWidget(m_generate);
    m_bottom_buttons_layout->addWidget(m_leave);
    m_bottom_buttons_layout->setContentsMargins(0, 70, 0, 0);

    m_main_layout->addRow("Choisissez le langage", m_language);
    m_main_layout->addRow("Nom du fichier", m_name);
    m_main_layout->addRow("Chemin du dossier", m_hbox_path_file);
    m_main_layout->addRow(m_bottom_buttons_layout);

    setLayout(m_main_layout);
    connect(m_button_path_file, SIGNAL(clicked()), this, SLOT(pathFileWindow()));
    connect(m_generate, SIGNAL(clicked()), this, SLOT(generate()));
    connect(m_leave, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void mainWindow::pathFileWindow()
{
    QFileDialog folder_path;
    QString folder_path_name;

    folder_path_name = folder_path.getExistingDirectory(this, tr("Open a directory"), "c://", QFileDialog::ShowDirsOnly);
    m_name_folder->setText(folder_path_name);
}

void mainWindow::generate()
{
    if (m_name->text() != NULL && m_name_folder->text() != NULL)
        mainWindow::call_generation();
    else if (m_name->text() == NULL)
        QMessageBox::critical(this, "", "Error : the name of the file is not specified");
    else
        QMessageBox::critical(this, "", "Error : the path of the folder is not specified");
}
