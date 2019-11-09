#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QFileDialog>
#include <QComboBox>
#include <QLabel>

class mainWindow : public QWidget
{
    Q_OBJECT

    public:
    mainWindow();
    void call_generation();
    void c_generation();
    void cpp_generation();
    void html_generation();
    void java_generation();
    void python_generation();

    public slots:
    void pathFileWindow();
    void generate();

    private:
    QFormLayout *m_main_layout, *m_path_layout;
    QVBoxLayout *m_main_box;
    QGroupBox *m_main_group;
    QComboBox *m_language;
    QLineEdit *m_name, *m_name_folder;
    QHBoxLayout *m_hbox_path_file;
    QPushButton *m_button_path_file;
    QHBoxLayout *m_bottom_buttons_layout;
    QPushButton *m_generate;
    QPushButton *m_leave;
};

#endif
