#include "app.h"
#include "./ui_app.h"
#include "math.h"

const int NUMBER_BUTTONS = 9; // Amount of buttons

// CONSTRUCTOR
app::app(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

// INITIALIZING VARIABLES
    mathPressed = false;
    commaSet = false;
    negSet = false;
    second_num = 0;
    first_num = 0;

// CONNECTING NUMBER BUTTONS TO numberButtonClicked() -function by using for loop
    for(int i = 0;i<=NUMBER_BUTTONS;i++){
        // Concatenating string "Button" and integer value (i)
        QString buttonName = "Button"+QString::number(i);
        // Finding QPushButton with our specific name by using findChild -function, and assigning it to button pointer
        QPushButton* button = this->findChild<QPushButton*>(buttonName);

        // If button is found, we connect the button with numberButtonClicked() -function
        if(button){
            connect(button, SIGNAL(clicked()), this, SLOT(numberButtonClicked()));
        } else {
            ui->Main_display->setText("Error");
        }
    }

// CONNECTING MATH BUTTONS
    connect(ui->Sum, SIGNAL(clicked()), this, SLOT(mathButtonClicked()));
    connect(ui->Subtraction, SIGNAL(clicked()), this, SLOT(mathButtonClicked()));
    connect(ui->Multiplication, SIGNAL(clicked()), this, SLOT(mathButtonClicked()));
    connect(ui->Division, SIGNAL(clicked()), this, SLOT(mathButtonClicked()));
    connect(ui->SquareRoot, SIGNAL(clicked()), this, SLOT(mathButtonClicked()));
    connect(ui->PowerTo, SIGNAL(clicked()), this, SLOT(mathButtonClicked()));
}

// DESTRUCTOR
app::~app()
{
    delete ui;
}

// DEFINING METHODS FOR BUTTONS

void app::numberButtonClicked()
{
    // Reading senders info
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if(button){
        userInput.push_back(button->text());
        if(!mathPressed)
        {
            first_num = userInput.toDouble();
            displayValue.push_back(button->text());
            ui->History_display->setText(" ");
            ui->Main_display->setText(QString::number(first_num));
        }
        else if(!squareRoot)
        {
            second_num = userInput.toDouble();
            ui->Main_display->setText(QString::number(second_num));
        }


    }


}

void app::mathButtonClicked()
{

    // Reading sender info
    QPushButton* button = qobject_cast<QPushButton*>(sender());


    if(!mathPressed && !displayValue.isEmpty()){

        // Operator triggers to false
        sum = false;
        subtraction = false;
        multiplication = false;
        division = false;
        squareRoot = false;
        powerTo = false;

        // Comparing senders info to operators
        if(button->text()=="+"){
            sum = true;
        }else if(button->text()=="-"){
            subtraction = true;
        }else if(button->text()=="*"){
            multiplication = true;
        }else if(button->text()=="/"){
            division = true;
        }else if(button->text()=="√x"){
            squareRoot = true;
        }else if(button->text()=="^x"){
            powerTo = true;
        }

        if(squareRoot){
            displayValue.push_front(" √ ");
        }else if(powerTo){
            displayValue.push_back(" ^ ");
        }
        else
        {
            displayValue.push_back(" "+button->text()+" ");
        }

        ui->History_display->setText(displayValue);
        ui->Main_display->setText(QString::number(first_num));

        commaSet = false;
        mathPressed = true;
        userInput = NULL;
    }

}


void app::on_Equal_clicked()
{
    if(sum){
        solution = first_num + second_num;
    }else if(subtraction){
        solution = first_num - second_num;
    }else if(multiplication){
        solution = first_num * second_num;
    }else if(division){
        solution = first_num / second_num;
    }else if(squareRoot){
        solution = sqrt(first_num);
    }else if(powerTo){
        solution = pow(first_num, second_num);
    }else{
        solution = first_num;
    }

    if(mathPressed){
    // Adding second num to displayvalue before we print it
    displayValue.push_back(QString::number(second_num)+" =");

    // Printing second number to history
    if(!squareRoot){
    ui->History_display->setText(displayValue);
    }

    // Checking if solution has decimals in it, and if so we will limit the decimals to 2
    // else we print the solution without decimals
    if (solution != static_cast<int>(solution)) {
        ui->Main_display->setText(QString::number(solution,'f',2));
    } else {
        ui->Main_display->setText(QString::number(solution,'f',0));
    }

    // Resetting
    solution = 0;
    first_num = 0;
    second_num = 0;
    displayValue = NULL;
    userInput = NULL;
    mathPressed = false;
    negSet = false;
    commaSet = false;
    }

}


void app::on_AC_clicked()
{
    negSet = false;
    sum = false;
    subtraction = false;
    multiplication = false;
    division = false;
    squareRoot = false;
    powerTo = false;
    commaSet = false;
    first_num = 0;
    second_num = 0;
    solution = 0;
    displayValue = NULL;
    userInput = NULL;
    ui->Main_display->setText("0");
    ui->History_display->setText(" ");
    mathPressed = false;
}


void app::on_ChangeSign_clicked()
{
    if(!mathPressed && !displayValue.isEmpty()){ // Changing sign for the first number
        first_num = -1 * first_num;
        if(!negSet){
            displayValue.push_front("-");
            userInput.push_front("-");
            negSet = true;
        }else{
            displayValue.remove("-");
            userInput.remove("-");
            negSet = false;
        }
        ui->Main_display->setText(displayValue);
    }
    else if(mathPressed && second_num) // Changing sign for the second number
    {
        second_num = -1 * second_num;

        if(!negSet){
            userInput.push_front("-");
            negSet = true;
        }else{
            userInput.remove("-");
            negSet = false;
        }

        ui->Main_display->setText(userInput);
    }

}


void app::on_Comma_clicked()
{
    if (!commaSet && first_num && !mathPressed) // If there is no comma
    {
        userInput.push_back(".");
        displayValue.push_back(".");
        ui->Main_display->setText(displayValue);
        commaSet = true;
    }
    else if(!commaSet && second_num && mathPressed){
        userInput.push_back(".");
        ui->Main_display->setText(QString::number(second_num)+".");
        commaSet = true;
    }
}

