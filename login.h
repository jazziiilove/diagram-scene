#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "database.h"

class Login : public QDialog
{
    Q_OBJECT
public:
    QLineEdit* userLineEdit;
    Login(QWidget* parent = 0);
    ~Login();

private slots:
    void OnQuit();
    void OnLogin();

private:
    void reject();

    QLabel* userLabel;
    QLabel* passLabel;

    QLineEdit* passLineEdit;
    QPushButton* loginButton;
    QPushButton* quitButton;
    Database database;
};

#endif // LOGIN_H
