#include "loadWindow.h"
#include <QMessageBox>
#include <fstream>

LoadWindow::LoadWindow () 
{
	setWindowTitle("Longboat Development");
	setStyleSheet("QPushButton:hover {color:red}");

	layout = new QVBoxLayout();

	userInstructions = new QLabel("Enter the filename for a saved portfolio:");
	layout->addWidget(userInstructions);

	filename = new QLineEdit();
	connect(filename, SIGNAL(returnPressed()), this, SLOT(loadPortfolio()));
	layout->addWidget(filename);

	loadButton = new QPushButton("Load Portfolio");
	connect(loadButton, SIGNAL(clicked()), this, SLOT(loadPortfolio()));
	layout->addWidget(loadButton);

	createButton = new QPushButton("Create Portfolio");
	connect(createButton, SIGNAL(clicked()), this, SLOT(create()));
	layout->addWidget(createButton);
	
	quitButton = new QPushButton("Quit");
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
	layout->addWidget(quitButton);

	setLayout(layout);

	portfolio = new Portfolio();
};

LoadWindow::~LoadWindow()
{
	delete userInstructions;
	delete filename;
	delete createButton;
	delete loadButton;
	delete quitButton;
	delete layout;
};

void LoadWindow::loadPortfolio () 
{
	//do nothing if no filename is given
	if(filename->text().isEmpty())
		return;

	std::string nameOfFile = filename->text().toStdString();

	std::ifstream inFile(nameOfFile.c_str());

	if(!inFile)
	{
		nameOfFile = "Unable to open \"" + nameOfFile + "\"";
		sendErrorMessage(nameOfFile);
		return;
	}
	portfolio->setName(nameOfFile);
	portfolio->readFile(inFile);
	portfolioManager = new PortfolioManager(portfolio);
	
	portfolioManager->show();
	this->hide();
};

void LoadWindow::create()
{
	portfolioManager = new PortfolioManager(portfolio);
	portfolio->setName("");
	this->hide();
	portfolioManager->show();
};

void LoadWindow::quit () 
{
	QApplication::exit();
};

void LoadWindow::sendErrorMessage(const std::string & message)
{
	QMessageBox errorMessage;
	errorMessage.setWindowTitle("Portfolio Load Error");
	errorMessage.setIcon(QMessageBox::Warning);
	errorMessage.setText(QString::fromStdString(message));
	errorMessage.exec();
	return;
};

