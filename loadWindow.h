#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include "portfolioManager.h"
#include "portfolio.h"

using namespace std;

class LoadWindow : public QWidget
{
	Q_OBJECT
public:
	LoadWindow();
	~LoadWindow();

private slots:
	void loadPortfolio();
	void quit();
	void create();

private:
	QPushButton* loadButton;
	QPushButton* createButton;
	QPushButton* quitButton;
	QLineEdit* filename;
	QVBoxLayout* layout;
	QLabel* userInstructions;
	PortfolioManager* portfolioManager;

	Portfolio* portfolio;
	void sendErrorMessage(const std::string & message);
};