#include "app.h"
#include "./ui_app.h"
#include "math.h"

app::app(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    const int NUMBER_BUTTONS = 9;
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

app::~app()
{
    delete ui;
}

// DEFINING METHODS

void app::numberButtonClicked()
{
    // Reading senders info
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if(button){

        userInput.push_back(button->text());

        if(!mathPressed)
        {
            first_num = userInput.toDouble(); // add ok later for error handling
            displayValue.push_back(button->text());
            ui->Main_display_2->setText(" ");
            ui->Main_display->setText(QString::number(first_num));
        }
        else if(!squareRoot)
        {
            second_num = userInput.toDouble();
            //displayValue.push_back(button->text());
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

        ui->Main_display_2->setText(displayValue);
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

    //adding second num to displayvalue before we print it
    displayValue.push_back(QString::number(second_num)+" =");
    //priting displayvalue to history
    ui->Main_display_2->setText(displayValue);
    //printing solution to main display
    ui->Main_display->setText(QString::number(solution));

    //resetting
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

// ALL CLEAR CLICKED
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
    ui->Main_display_2->setText(" ");
    mathPressed = false;
}

/*    if(!mathPressed && displayValue.isEmpty()){
        return;
    }else if(!mathPressed){
        displayValue.push_back(button->text());
        ui->Main_display->setText(displayValue);
        mathPressed = true;
    }*/


// CHANGE SIGN BUTTON CLICKED
void app::on_ChangeSign_clicked()
{
    if(!mathPressed && !displayValue.isEmpty()){
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
        //displayValue = ui->Main_display->text();
    }
    else if(mathPressed && second_num)
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

// ADD COMMA
void app::on_Comma_clicked()
{
    if (!commaSet && first_num && !mathPressed) // if there is no comma
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

