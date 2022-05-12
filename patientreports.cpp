#include "patientreports.h"
#include "ui_patientreportsdisplay.h"
#include "ui_patientreports.h"
#include <QSqlQuery>
#include <QChart>
#include <QBarSet>
#include <QStringList>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QBarSeries>
#include <QChartView>
#include <QGridLayout>
#include <QLayoutItem>
#include <QFrame>
#include <QHBoxLayout>
#include <patientreportsdisplay.h>
#include <QPieSeries>
#include <QPieSlice>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QLabel>
#include <vector>
using std::vector;

PatientReports::PatientReports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientReports)
{
    ui->setupUi(this);
    connect(ui->deceasedPatientsButton, SIGNAL(clicked()), this, SLOT(generateDeceasedPatientsReport()));
    connect(ui->patientsOnTreatmentButton, SIGNAL(clicked()), this, SLOT(generatePatientsOnTreatmentReport()));
    connect(ui->patientsNeedingBloodButton, SIGNAL(clicked()), this, SLOT(generatePatientsNeedingBloodReport()));

}

PatientReports::~PatientReports()
{
    delete ui;
}

void PatientReports::generateDeceasedPatientsReport()
{
    patientReportsDisplay * chartDisplay = new patientReportsDisplay(this);

    //graph of male and female deceased patients with a specific blood type------------------------GRAPH1
    vector<int>bloodtypeCounts;

    //--males of blood type A+
    QSqlQueryModel male_Aplus;
    male_Aplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.BloodType_id = 'A+';");
    int male_Apositive = male_Aplus.data(male_Aplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Apositive);
    //--females of blood type A+
    QSqlQueryModel female_Aplus;
    female_Aplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.BloodType_id = 'A+';");
    int female_Apositive = female_Aplus.data(female_Aplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Apositive);

    //--males of blood type A-
    QSqlQueryModel male_Aminus;
    male_Aminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.BloodType_id = 'A-';");
    int male_Anegative = male_Aminus.data(male_Aminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Anegative);
    //--females of blood type A-
    QSqlQueryModel female_Aminus;
    female_Aminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.BloodType_id = 'A-';");
    int female_Anegative = female_Aminus.data(female_Aminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Anegative);

    //--males of blood type B+
    QSqlQueryModel male_Bplus;
    male_Bplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.BloodType_id = 'B+';");
    int male_Bpositive = male_Bplus.data(male_Bplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Bpositive);
    //--females of blood type B+
    QSqlQueryModel female_Bplus;
    female_Bplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.BloodType_id = 'B+';");
    int female_Bpositive = female_Bplus.data(female_Bplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Bpositive);

    //--males of blood type B-
    QSqlQueryModel male_Bminus;
    male_Bminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.BloodType_id = 'B-';");
    int male_Bnegative = male_Bminus.data(male_Bminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Bnegative);
    //--females of blood type B-
    QSqlQueryModel female_Bminus;
    female_Bminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.BloodType_id = 'B-';");
    int female_Bnegative = female_Bminus.data(female_Bminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Bnegative);

    //--males of blood type AB+
    QSqlQueryModel male_ABplus;
    male_ABplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.BloodType_id = 'AB+';");
    int male_ABpositive = male_ABplus.data(male_ABplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_ABpositive);
    //--females of blood type AB+
    QSqlQueryModel female_ABplus;
    female_ABplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.BloodType_id = 'AB+';");
    int female_ABpositive = female_ABplus.data(female_ABplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_ABpositive);

    //--males of blood type AB-
    QSqlQueryModel male_ABminus;
    male_ABminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.BloodType_id = 'AB-';");
    int male_ABnegative = male_ABminus.data(male_ABminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_ABnegative);
    //--females of blood type AB-
    QSqlQueryModel female_ABminus;
    female_ABminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.BloodType_id = 'AB-';");
    int female_ABnegative = female_ABminus.data(female_ABminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_ABnegative);

    //--males of blood type O+
    QSqlQueryModel male_Oplus;
    male_Oplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.BloodType_id = 'O+';");
    int male_Opositive = male_Oplus.data(male_Oplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Opositive);
    //--females of blood type O+
    QSqlQueryModel female_Oplus;
    female_Oplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.BloodType_id = 'O+';");
    int female_Opositive = female_Oplus.data(female_Oplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Opositive);

    //--males of blood type O-
    QSqlQueryModel male_Ominus;
    male_Ominus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.BloodType_id = 'O-';");
    int male_Onegative = male_Ominus.data(male_Ominus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Onegative);
    //--females of blood type O-
    QSqlQueryModel female_Ominus;
    female_Ominus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.BloodType_id = 'O-';");
    int female_Onegative = female_Ominus.data(female_Ominus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Onegative);


    QBarSet *bloodTypeMales = new QBarSet(tr("Male"));
    QBarSet *bloodTypeFemales = new QBarSet(tr("Female"));

    *bloodTypeMales << male_Apositive << male_Anegative << male_Bpositive << male_Bnegative <<  male_ABpositive << male_ABnegative << male_Opositive << male_Onegative;
    *bloodTypeFemales << female_Apositive << female_Anegative << female_Bpositive << female_Bnegative <<  female_ABpositive << female_ABnegative << female_Opositive << female_Onegative;

    QBarSeries *seriesBloodType = new QBarSeries();
    seriesBloodType->append(bloodTypeMales);
    seriesBloodType->append(bloodTypeFemales);

    QChart *chartBloodTypes = new QChart();
    chartBloodTypes->addSeries(seriesBloodType);
    chartBloodTypes->setTitle(tr("Deceased Patients BloodTypes"));
    chartBloodTypes->setAnimationOptions(QChart::SeriesAnimations);

    chartBloodTypes->legend()->setVisible(true); //setVisible
    chartBloodTypes->legend()->setAlignment(Qt::AlignBottom);

    QStringList categoriesBloodTypes;
    categoriesBloodTypes << "A+" << "A-" << "B+" << "B-" << "AB+" << "AB-" << "O+" << "O-";
    QBarCategoryAxis *axisXBloodTypeChart = new QBarCategoryAxis();
    axisXBloodTypeChart->append(categoriesBloodTypes);
    chartBloodTypes->addAxis(axisXBloodTypeChart, Qt::AlignBottom);
    seriesBloodType->attachAxis(axisXBloodTypeChart);

    QValueAxis *axisYBloodTypeChart = new QValueAxis();
    axisYBloodTypeChart->setRange(0, *max_element(bloodtypeCounts.begin(), bloodtypeCounts.end()));
    chartBloodTypes->addAxis(axisYBloodTypeChart, Qt::AlignLeft);
    seriesBloodType->attachAxis(axisYBloodTypeChart);

    QChartView *chartViewBloodType = new QChartView(chartBloodTypes);
    chartViewBloodType->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewBloodType, 0, 0); //adding the chartview to the gridlayout



    //graph of male and female deceased patients living in different districts---------------------GRAPH2
    vector<int>districtCounts;

    //--males living in Corozal
    QSqlQueryModel male_Corozal;
    male_Corozal.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.District = 'Corozal';");
    int male_corozalresident = male_Corozal.data(male_Corozal.index(0, 0)).toInt(); districtCounts.push_back(male_corozalresident);
    //--females living in Corozal
    QSqlQueryModel female_Corozal;
    female_Corozal.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.District = 'Corozal';");
    int female_corozalresident = female_Corozal.data(female_Corozal.index(0, 0)).toInt(); districtCounts.push_back(female_corozalresident);

    //--males living in Orange Walk
    QSqlQueryModel male_OrangeWalk;
    male_OrangeWalk.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.District = 'Orange Walk';");
    int male_owresident = male_OrangeWalk.data(male_OrangeWalk.index(0, 0)).toInt(); districtCounts.push_back(male_owresident);
    //--females living in Orange Walk
    QSqlQueryModel female_OrangeWalk;
    female_OrangeWalk.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.District = 'Orange Walk';");
    int female_owresident = female_OrangeWalk.data(female_OrangeWalk.index(0, 0)).toInt(); districtCounts.push_back(female_owresident);

    //--males living in Belize
    QSqlQueryModel male_Belize;
    male_Belize.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.District = 'Belize';");
    int male_belizeresident = male_Belize.data(male_Belize.index(0, 0)).toInt(); districtCounts.push_back(male_belizeresident);
    //--females living in Belize
    QSqlQueryModel female_Belize;
    female_Belize.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.District = 'Belize';");
    int female_belizeresident = female_Belize.data(female_Belize.index(0, 0)).toInt(); districtCounts.push_back(female_belizeresident);

    //--males living in Cayo
    QSqlQueryModel male_Cayo;
    male_Cayo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.District = 'Cayo';");
    int male_cayoresident = male_Cayo.data(male_Cayo.index(0, 0)).toInt(); districtCounts.push_back(male_cayoresident);
    //--females living in Cayo
    QSqlQueryModel female_Cayo;
    female_Cayo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.District = 'Cayo';");
    int female_cayoresident = female_Cayo.data(female_Cayo.index(0, 0)).toInt(); districtCounts.push_back(female_cayoresident);

    //--males living in Stann Creek
    QSqlQueryModel male_StannCreek;
    male_StannCreek.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.District = 'Stann Creek';");
    int male_stanncreekresident = male_StannCreek.data(male_StannCreek.index(0, 0)).toInt(); districtCounts.push_back(male_stanncreekresident);
    //--females living in Stann Creek
    QSqlQueryModel female_StannCreek;
    female_StannCreek.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.District = 'Stann Creek';");
    int female_stanncreekresident = female_StannCreek.data(female_StannCreek.index(0, 0)).toInt(); districtCounts.push_back(female_stanncreekresident);

    //--males living in Stann Creek
    QSqlQueryModel male_Toledo;
    male_Toledo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Male' && patient.District = 'Toledo';");
    int male_toledoresident = male_Toledo.data(male_Toledo.index(0, 0)).toInt(); districtCounts.push_back(male_toledoresident);
    //--females living in Stann Creek
    QSqlQueryModel female_Toledo;
    female_Toledo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'Deceased' && patient.Gender = 'Female' && patient.District = 'Toledo';");
    int female_toledoresident = female_Toledo.data(female_Toledo.index(0, 0)).toInt(); districtCounts.push_back(female_toledoresident);


    QBarSet *districtMales = new QBarSet(tr("Male"));
    QBarSet *districtFemales = new QBarSet(tr("Female"));
    *districtMales << male_corozalresident << male_owresident << male_belizeresident << male_cayoresident << male_stanncreekresident << male_toledoresident;
    *districtFemales << female_corozalresident << female_owresident <<  female_belizeresident << female_cayoresident << female_stanncreekresident << female_toledoresident;

    QBarSeries *seriesDistricts = new QBarSeries();
    seriesDistricts->append(districtMales);
    seriesDistricts->append(districtFemales);

    QChart *chartDistricts = new QChart();
    chartDistricts->addSeries(seriesDistricts);
    chartDistricts->setTitle(tr("Deceased Patients District Location"));
    chartDistricts->setAnimationOptions(QChart::SeriesAnimations);

    chartDistricts->legend()->setVisible(true); //setVisible(true)
    chartDistricts->legend()->setAlignment(Qt::AlignBottom);

    QStringList categoriesDistricts;
    categoriesDistricts << "Corozal" << "Orange Walk" << "Belize" << "Cayo" << "Stann Creek" << "Toledo" ;
    QBarCategoryAxis *axisXDistrictChart = new QBarCategoryAxis();
    axisXDistrictChart->append(categoriesDistricts);
    chartDistricts->addAxis(axisXDistrictChart, Qt::AlignBottom);
    seriesDistricts->attachAxis(axisXDistrictChart);

    QValueAxis *axisYDistrictChart = new QValueAxis();
    axisYDistrictChart->setRange(0, *max_element(districtCounts.begin(), districtCounts.end()));
    chartDistricts->addAxis(axisYDistrictChart, Qt::AlignLeft);
    seriesDistricts->attachAxis(axisYDistrictChart);

    QChartView *chartViewDistricts = new QChartView(chartDistricts);
    chartViewDistricts->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewDistricts, 0, 1);


    qDebug()<<"A+ Male count " << male_Apositive << "and female is" << female_Apositive;
    qDebug()<<"A- Male count " << male_Anegative << "and female is" << female_Anegative;
    qDebug()<<"B+ Male count " << male_Bpositive << "and female is" << female_Bpositive;
    qDebug()<<"B- Male count " << male_Bnegative << "and female is" << female_Bnegative;
    qDebug()<<"AB+ Male count " << male_ABpositive << "and female is" << female_ABpositive;
    qDebug()<<"AB- Male count " << male_ABnegative << "and female is" << female_ABnegative;
    qDebug()<<"O+ Male count " << male_Opositive << "and female is" << female_Opositive ;
    qDebug()<<"O- Male count " << male_Onegative << "and female is" << female_Onegative;

    qDebug()<< "Corozal female count " << female_corozalresident <<  " and male is  "  << male_corozalresident;
    qDebug()<< "Orange Walk female count " << female_owresident << " and male is  "  << male_owresident;
    qDebug()<< "Belize female count " << female_belizeresident << " and male is  "  << male_belizeresident;
    qDebug()<< "Cayo female count " << female_cayoresident << " and male is  "  << male_cayoresident;
    qDebug()<< "Stann Creek female count " << female_stanncreekresident << " and male is  "  << male_stanncreekresident;
    qDebug()<< "Toledo female count " << female_toledoresident << " and male is  "  << male_toledoresident;


    qDebug()<<"step 1";
    //graph of the numbers of year frequencies deceased patients have had diabetes---------------------GRAPH3
    vector<int>years;
    vector<int>frequencies;

    QSqlQuery yearsWithDiabetes("SELECT patient.Years_with_diabetes, COUNT(patient.Years_with_diabetes)AS Frequency FROM patient WHERE patient.Patient_status = 'Deceased' GROUP BY patient.Years_with_diabetes ORDER BY COUNT(patient.Years_with_diabetes) DESC;");
    int col_1 = yearsWithDiabetes.record().indexOf("Years_with_diabetes");
    int col_2 = yearsWithDiabetes.record().indexOf("Frequency");
    while (yearsWithDiabetes.next()) {
        years.push_back(yearsWithDiabetes.value(col_1).toInt());
        frequencies.push_back(yearsWithDiabetes.value(col_2).toInt());
    }
    //list of years and their frequencies to which they occur are saved

    qDebug()<<"step 2";
    QPieSeries *seriesYearsWithDiabetes= new QPieSeries();

    int check = 0;
    try{
        for(int i = 0; i < years.size(); i++){
            if(years[i] == 0){
                continue;
            }else{
                check++;
                seriesYearsWithDiabetes->append(QString::number(years[i]), frequencies[i]);
            }
        }
    }catch(...){
        qDebug()<<"error occured at line 295 in patientreports.cpp";
    }

    qDebug()<<"step 3";
    try{
        if(check != 0){
            QPieSlice *sliceYearsWithDiabetes = seriesYearsWithDiabetes->slices().at(0);
            sliceYearsWithDiabetes->setExploded();
            sliceYearsWithDiabetes->setLabelVisible();
            sliceYearsWithDiabetes->setPen(QPen(Qt::red, 2));
            sliceYearsWithDiabetes->setBrush(Qt::red);
        }
    }catch(...){
        qDebug()<<"error occured";
    }


    qDebug()<<"step break";

    QChart *chartYearsWithDiabetes = new QChart();
    chartYearsWithDiabetes->addSeries(seriesYearsWithDiabetes);
    chartYearsWithDiabetes->setTitle(tr("Frequency of years that deceased patients had Diabetes"));
    chartYearsWithDiabetes->legend()->setVisible(true);

    QChartView *chartViewYearsWithDiabetes = new QChartView(chartYearsWithDiabetes);
    chartViewYearsWithDiabetes->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewYearsWithDiabetes, 1, 1);


    //graph of the numbers of years deceased patients have had hypertension---------------------GRAPH4
    years.clear();
    frequencies.clear();

    qDebug()<<"step 4";
    QSqlQuery yearsWithHypertension("SELECT patient.Years_with_hypertension, COUNT(patient.Years_with_hypertension)AS Frequency FROM patient WHERE patient.Patient_status = 'Deceased' GROUP BY patient.Years_with_hypertension ORDER BY COUNT(patient.Years_with_hypertension) DESC;");
    col_1 = yearsWithHypertension.record().indexOf("Years_with_hypertension");
    col_2 = yearsWithHypertension.record().indexOf("Frequency");
    while (yearsWithHypertension.next()) {
        years.push_back(yearsWithHypertension.value(col_1).toInt());
        frequencies.push_back(yearsWithHypertension.value(col_2).toInt());
    }
    //list of years and their frequencies to which they occur are saved

    QPieSeries *seriesYearsWithHypertension = new QPieSeries();

    check = 0;
    qDebug()<<"step 5";
    try{
        for(int i = 0; i < years.size(); i++){
            if(years[i] == 0){
                continue;
            }else{
                check++;
                seriesYearsWithHypertension->append(QString::number(years[i]), frequencies[i]);
            }
        }
    }catch(...){
        qDebug()<<"error occured at line 339 in patientreports.cpp";
    }

    try{
        if(check != 0){
            QPieSlice *sliceYearsWithHypertension = seriesYearsWithHypertension->slices().at(0);
            sliceYearsWithHypertension->setExploded();
            sliceYearsWithHypertension->setLabelVisible();
            sliceYearsWithHypertension->setPen(QPen(Qt::red, 2));
            sliceYearsWithHypertension->setBrush(Qt::red);
        }
    }catch(...){
        qDebug()<<"error on line 367 in patientreports.cpp";
    }

    QChart *chartYearsWithHypertension = new QChart();
    chartYearsWithHypertension->addSeries(seriesYearsWithHypertension);
    chartYearsWithHypertension->setTitle(tr("Frequency of years that deceased patients had Hypertension"));
    chartYearsWithHypertension->legend()->setVisible(true);

    QChartView *chartViewYearsWithHypertension = new QChartView(chartYearsWithHypertension);
    chartViewYearsWithHypertension->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewYearsWithHypertension, 1, 0);






    //count of deceased patients with diabetes type 1 and diabetes type 2--------------------query1
    QSqlQueryModel diabetesType1;
    diabetesType1.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'Deceased' && patient.Diabetes_type1 = 1;");
    int type1 = diabetesType1.data(diabetesType1.index(0, 0)).toInt();

    //count of patients with urinating problems--------------------query2
    QSqlQueryModel diabetesType2;
    diabetesType2.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'Deceased' && patient.Diabetes_type2 = 1;");
    int type2 = diabetesType2.data(diabetesType2.index(0, 0)).toInt();


    //count of patients with high blood pressure--------------------query3
    QSqlQueryModel highBloodPressure;
    highBloodPressure.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'Deceased' && patient.Blood_sugar > 130;");
    int bloodPressure = highBloodPressure.data(highBloodPressure.index(0, 0)).toInt();


    //count of patients with urinating problems--------------------query4
    QSqlQueryModel urinatingProblems;
    urinatingProblems.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'Deceased' && patient.Urinating_problems = 1;");
    int urinationP = urinatingProblems.data(urinatingProblems.index(0, 0)).toInt();


    chartDisplay->ui->labelDiabetesType1->setText(QString(tr("Type 1 Diabetes count: %1")).arg(type1));

    chartDisplay->ui->labelDiabetesType2->setText(QString(tr("Type 2 Diabetes count: %1")).arg(type2));


    chartDisplay->ui->labelHIghBloodPressure->setText(QString(tr("High Blood Pressure count: %1")).arg(bloodPressure));

    chartDisplay->ui->labelUrinatingProblems->setText(QString(tr("Urination Problems count: %1")).arg(urinationP));



    chartDisplay->setWindowFlag(Qt::Window);
    chartDisplay->show();
}

void PatientReports::generatePatientsOnTreatmentReport()
{

    patientReportsDisplay * chartDisplay = new patientReportsDisplay(this);

    //graph of male and female deceased patients with a specific blood type------------------------GRAPH1
    vector<int>bloodtypeCounts;

    //--males of blood type A+
    QSqlQueryModel male_Aplus;
    male_Aplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.BloodType_id = 'A+';");
    int male_Apositive = male_Aplus.data(male_Aplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Apositive);
    //--females of blood type A+
    QSqlQueryModel female_Aplus;
    female_Aplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.BloodType_id = 'A+';");
    int female_Apositive = female_Aplus.data(female_Aplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Apositive);

    //--males of blood type A-
    QSqlQueryModel male_Aminus;
    male_Aminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.BloodType_id = 'A-';");
    int male_Anegative = male_Aminus.data(male_Aminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Anegative);
    //--females of blood type A-
    QSqlQueryModel female_Aminus;
    female_Aminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.BloodType_id = 'A-';");
    int female_Anegative = female_Aminus.data(female_Aminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Anegative);

    //--males of blood type B+
    QSqlQueryModel male_Bplus;
    male_Bplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.BloodType_id = 'B+';");
    int male_Bpositive = male_Bplus.data(male_Bplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Bpositive);
    //--females of blood type B+
    QSqlQueryModel female_Bplus;
    female_Bplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.BloodType_id = 'B+';");
    int female_Bpositive = female_Bplus.data(female_Bplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Bpositive);

    //--males of blood type B-
    QSqlQueryModel male_Bminus;
    male_Bminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.BloodType_id = 'B-';");
    int male_Bnegative = male_Bminus.data(male_Bminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Bnegative);
    //--females of blood type B-
    QSqlQueryModel female_Bminus;
    female_Bminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.BloodType_id = 'B-';");
    int female_Bnegative = female_Bminus.data(female_Bminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Bnegative);

    //--males of blood type AB+
    QSqlQueryModel male_ABplus;
    male_ABplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.BloodType_id = 'AB+';");
    int male_ABpositive = male_ABplus.data(male_ABplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_ABpositive);
    //--females of blood type AB+
    QSqlQueryModel female_ABplus;
    female_ABplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.BloodType_id = 'AB+';");
    int female_ABpositive = female_ABplus.data(female_ABplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_ABpositive);

    //--males of blood type AB-
    QSqlQueryModel male_ABminus;
    male_ABminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.BloodType_id = 'AB-';");
    int male_ABnegative = male_ABminus.data(male_ABminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_ABnegative);
    //--females of blood type AB-
    QSqlQueryModel female_ABminus;
    female_ABminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.BloodType_id = 'AB-';");
    int female_ABnegative = female_ABminus.data(female_ABminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_ABnegative);

    //--males of blood type O+
    QSqlQueryModel male_Oplus;
    male_Oplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.BloodType_id = 'O+';");
    int male_Opositive = male_Oplus.data(male_Oplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Opositive);
    //--females of blood type O+
    QSqlQueryModel female_Oplus;
    female_Oplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.BloodType_id = 'O+';");
    int female_Opositive = female_Oplus.data(female_Oplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Opositive);

    //--males of blood type O-
    QSqlQueryModel male_Ominus;
    male_Ominus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.BloodType_id = 'O-';");
    int male_Onegative = male_Ominus.data(male_Ominus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Onegative);
    //--females of blood type O-
    QSqlQueryModel female_Ominus;
    female_Ominus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.BloodType_id = 'O-';");
    int female_Onegative = female_Ominus.data(female_Ominus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Onegative);


    QBarSet *bloodTypeMales = new QBarSet(tr("Male"));
    QBarSet *bloodTypeFemales = new QBarSet(tr("Female"));

    *bloodTypeMales << male_Apositive << male_Anegative << male_Bpositive << male_Bnegative <<  male_ABpositive << male_ABnegative << male_Opositive << male_Onegative;
    *bloodTypeFemales << female_Apositive << female_Anegative << female_Bpositive << female_Bnegative <<  female_ABpositive << female_ABnegative << female_Opositive << female_Onegative;

    QBarSeries *seriesBloodType = new QBarSeries();
    seriesBloodType->append(bloodTypeMales);
    seriesBloodType->append(bloodTypeFemales);

    QChart *chartBloodTypes = new QChart();
    chartBloodTypes->addSeries(seriesBloodType);
    chartBloodTypes->setTitle(tr("'On Treatment' Patients BloodTypes"));
    chartBloodTypes->setAnimationOptions(QChart::SeriesAnimations);

    chartBloodTypes->legend()->setVisible(true); //setVisible
    chartBloodTypes->legend()->setAlignment(Qt::AlignBottom);

    QStringList categoriesBloodTypes;
    categoriesBloodTypes << "A+" << "A-" << "B+" << "B-" << "AB+" << "AB-" << "O+" << "O-";
    QBarCategoryAxis *axisXBloodTypeChart = new QBarCategoryAxis();
    axisXBloodTypeChart->append(categoriesBloodTypes);
    chartBloodTypes->addAxis(axisXBloodTypeChart, Qt::AlignBottom);
    seriesBloodType->attachAxis(axisXBloodTypeChart);

    QValueAxis *axisYBloodTypeChart = new QValueAxis();
    axisYBloodTypeChart->setRange(0, *max_element(bloodtypeCounts.begin(), bloodtypeCounts.end()));
    chartBloodTypes->addAxis(axisYBloodTypeChart, Qt::AlignLeft);
    seriesBloodType->attachAxis(axisYBloodTypeChart);

    QChartView *chartViewBloodType = new QChartView(chartBloodTypes);
    chartViewBloodType->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewBloodType, 0, 0);



    //graph of male and female deceased patients living in different districts---------------------GRAPH2
    vector<int>districtCounts;

    //--males living in Corozal
    QSqlQueryModel male_Corozal;
    male_Corozal.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.District = 'Corozal';");
    int male_corozalresident = male_Corozal.data(male_Corozal.index(0, 0)).toInt(); districtCounts.push_back(male_corozalresident);
    //--females living in Corozal
    QSqlQueryModel female_Corozal;
    female_Corozal.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.District = 'Corozal';");
    int female_corozalresident = female_Corozal.data(female_Corozal.index(0, 0)).toInt(); districtCounts.push_back(female_corozalresident);

    //--males living in Orange Walk
    QSqlQueryModel male_OrangeWalk;
    male_OrangeWalk.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.District = 'Orange Walk';");
    int male_owresident = male_OrangeWalk.data(male_OrangeWalk.index(0, 0)).toInt(); districtCounts.push_back(male_owresident);
    //--females living in Orange Walk
    QSqlQueryModel female_OrangeWalk;
    female_OrangeWalk.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.District = 'Orange Walk';");
    int female_owresident = female_OrangeWalk.data(female_OrangeWalk.index(0, 0)).toInt(); districtCounts.push_back(female_owresident);

    //--males living in Belize
    QSqlQueryModel male_Belize;
    male_Belize.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.District = 'Belize';");
    int male_belizeresident = male_Belize.data(male_Belize.index(0, 0)).toInt(); districtCounts.push_back(male_belizeresident);
    //--females living in Belize
    QSqlQueryModel female_Belize;
    female_Belize.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.District = 'Belize';");
    int female_belizeresident = female_Belize.data(female_Belize.index(0, 0)).toInt(); districtCounts.push_back(female_belizeresident);

    //--males living in Cayo
    QSqlQueryModel male_Cayo;
    male_Cayo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.District = 'Cayo';");
    int male_cayoresident = male_Cayo.data(male_Cayo.index(0, 0)).toInt(); districtCounts.push_back(male_cayoresident);
    //--females living in Cayo
    QSqlQueryModel female_Cayo;
    female_Cayo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.District = 'Cayo';");
    int female_cayoresident = female_Cayo.data(female_Cayo.index(0, 0)).toInt(); districtCounts.push_back(female_cayoresident);

    //--males living in Stann Creek
    QSqlQueryModel male_StannCreek;
    male_StannCreek.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.District = 'Stann Creek';");
    int male_stanncreekresident = male_StannCreek.data(male_StannCreek.index(0, 0)).toInt(); districtCounts.push_back(male_stanncreekresident);
    //--females living in Stann Creek
    QSqlQueryModel female_StannCreek;
    female_StannCreek.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.District = 'Stann Creek';");
    int female_stanncreekresident = female_StannCreek.data(female_StannCreek.index(0, 0)).toInt(); districtCounts.push_back(female_stanncreekresident);

    //--males living in Stann Creek
    QSqlQueryModel male_Toledo;
    male_Toledo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Male' && patient.District = 'Toledo';");
    int male_toledoresident = male_Toledo.data(male_Toledo.index(0, 0)).toInt(); districtCounts.push_back(male_toledoresident);
    //--females living in Stann Creek
    QSqlQueryModel female_Toledo;
    female_Toledo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'On Treatment' && patient.Gender = 'Female' && patient.District = 'Toledo';");
    int female_toledoresident = female_Toledo.data(female_Toledo.index(0, 0)).toInt(); districtCounts.push_back(female_toledoresident);


    QBarSet *districtMales = new QBarSet(tr("Male"));
    QBarSet *districtFemales = new QBarSet(tr("Female"));
    *districtMales << male_corozalresident << male_owresident << male_belizeresident << male_cayoresident << male_stanncreekresident << male_toledoresident;
    *districtFemales << female_corozalresident << female_owresident <<  female_belizeresident << female_cayoresident << female_stanncreekresident << female_toledoresident;

    QBarSeries *seriesDistricts = new QBarSeries();
    seriesDistricts->append(districtMales);
    seriesDistricts->append(districtFemales);

    QChart *chartDistricts = new QChart();
    chartDistricts->addSeries(seriesDistricts);
    chartDistricts->setTitle(tr("'On Treatment' Patients District Location"));
    chartDistricts->setAnimationOptions(QChart::SeriesAnimations);

    chartDistricts->legend()->setVisible(true); //setVisible(true)
    chartDistricts->legend()->setAlignment(Qt::AlignBottom);

    QStringList categoriesDistricts;
    categoriesDistricts << "Corozal" << "Orange Walk" << "Belize" << "Cayo" << "Stann Creek" << "Toledo" ;
    QBarCategoryAxis *axisXDistrictChart = new QBarCategoryAxis();
    axisXDistrictChart->append(categoriesDistricts);
    chartDistricts->addAxis(axisXDistrictChart, Qt::AlignBottom);
    seriesDistricts->attachAxis(axisXDistrictChart);

    QValueAxis *axisYDistrictChart = new QValueAxis();
    axisYDistrictChart->setRange(0, *max_element(districtCounts.begin(), districtCounts.end()));
    chartDistricts->addAxis(axisYDistrictChart, Qt::AlignLeft);
    seriesDistricts->attachAxis(axisYDistrictChart);

    QChartView *chartViewDistricts = new QChartView(chartDistricts);
    chartViewDistricts->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewDistricts, 0, 1);


    qDebug()<<"A+ Male count " << male_Apositive << "and female is" << female_Apositive;
    qDebug()<<"A- Male count " << male_Anegative << "and female is" << female_Anegative;
    qDebug()<<"B+ Male count " << male_Bpositive << "and female is" << female_Bpositive;
    qDebug()<<"B- Male count " << male_Bnegative << "and female is" << female_Bnegative;
    qDebug()<<"AB+ Male count " << male_ABpositive << "and female is" << female_ABpositive;
    qDebug()<<"AB- Male count " << male_ABnegative << "and female is" << female_ABnegative;
    qDebug()<<"O+ Male count " << male_Opositive << "and female is" << female_Opositive ;
    qDebug()<<"O- Male count " << male_Onegative << "and female is" << female_Onegative;

    qDebug()<< "Corozal female count " << female_corozalresident <<  " and male is  "  << male_corozalresident;
    qDebug()<< "Orange Walk female count " << female_owresident << " and male is  "  << male_owresident;
    qDebug()<< "Belize female count " << female_belizeresident << " and male is  "  << male_belizeresident;
    qDebug()<< "Cayo female count " << female_cayoresident << " and male is  "  << male_cayoresident;
    qDebug()<< "Stann Creek female count " << female_stanncreekresident << " and male is  "  << male_stanncreekresident;
    qDebug()<< "Toledo female count " << female_toledoresident << " and male is  "  << male_toledoresident;


    //graph of the numbers of year frequencies deceased patients have had diabetes---------------------GRAPH3
    vector<int>years;
    vector<int>frequencies;

    QSqlQuery yearsWithDiabetes("SELECT patient.Years_with_diabetes, COUNT(patient.Years_with_diabetes)AS Frequency FROM patient WHERE patient.Patient_status = 'On Treatment' GROUP BY patient.Years_with_diabetes ORDER BY COUNT(patient.Years_with_diabetes) DESC;");
    int col_1 = yearsWithDiabetes.record().indexOf("Years_with_diabetes");
    int col_2 = yearsWithDiabetes.record().indexOf("Frequency");
    while (yearsWithDiabetes.next()) {
        years.push_back(yearsWithDiabetes.value(col_1).toInt());
        frequencies.push_back(yearsWithDiabetes.value(col_2).toInt());
    }
    //list of years and their frequencies to which they occur are saved

    QPieSeries *seriesYearsWithDiabetes= new QPieSeries();

    int check = 0;

    for(int i = 0; i < years.size(); i++){
        if(years[i] == 0){
            continue;
        }else{
            check++;
            seriesYearsWithDiabetes->append(QString::number(years[i]), frequencies[i]);
        }
    }

    try{
        if(check != 0){
            QPieSlice *sliceYearsWithDiabetes = seriesYearsWithDiabetes->slices().at(0);
            sliceYearsWithDiabetes->setExploded();
            sliceYearsWithDiabetes->setLabelVisible();
            sliceYearsWithDiabetes->setPen(QPen(Qt::red, 2));
            sliceYearsWithDiabetes->setBrush(Qt::red);
        }
    }catch(...){
        qDebug()<<"error on line 686 in patientreports.cpp";
    }

    QChart *chartYearsWithDiabetes = new QChart();
    chartYearsWithDiabetes->addSeries(seriesYearsWithDiabetes);
    chartYearsWithDiabetes->setTitle(tr("Frequency of years that 'On Treatment' patients had Diabetes"));
    chartYearsWithDiabetes->legend()->setVisible(true);

    QChartView *chartViewYearsWithDiabetes = new QChartView(chartYearsWithDiabetes);
    chartViewYearsWithDiabetes->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewYearsWithDiabetes, 1, 1);


    //graph of the numbers of years deceased patients have had hypertension---------------------GRAPH4
    years.clear();
    frequencies.clear();

    QSqlQuery yearsWithHypertension("SELECT patient.Years_with_hypertension, COUNT(patient.Years_with_hypertension)AS Frequency FROM patient WHERE patient.Patient_status = 'On Treatment' GROUP BY patient.Years_with_hypertension ORDER BY COUNT(patient.Years_with_hypertension) DESC;");
    col_1 = yearsWithHypertension.record().indexOf("Years_with_hypertension");
    col_2 = yearsWithHypertension.record().indexOf("Frequency");
    while (yearsWithHypertension.next()) {
        years.push_back(yearsWithHypertension.value(col_1).toInt());
        frequencies.push_back(yearsWithHypertension.value(col_2).toInt());
    }
    //list of years and their frequencies to which they occur are saved

    QPieSeries *seriesYearsWithHypertension = new QPieSeries();

    check = 0;

    for(int i = 0; i < years.size(); i++){
        if(years[i] == 0){
            continue;
        }else{
            check++;
            seriesYearsWithHypertension->append(QString::number(years[i]), frequencies[i]);
        }
    }

    try{
        if(check != 0){
            QPieSlice *sliceYearsWithHypertension = seriesYearsWithHypertension->slices().at(0);
            sliceYearsWithHypertension->setExploded();
            sliceYearsWithHypertension->setLabelVisible();
            sliceYearsWithHypertension->setPen(QPen(Qt::red, 2));
            sliceYearsWithHypertension->setBrush(Qt::red);
        }
    }catch(...){
        qDebug()<<"error on line 735 in patientreports.cpp";
    }

    QChart *chartYearsWithHypertension = new QChart();
    chartYearsWithHypertension->addSeries(seriesYearsWithHypertension);
    chartYearsWithHypertension->setTitle(tr("Frequency of years that 'On Treatment' patients had Hypertension"));
    chartYearsWithHypertension->legend()->setVisible(true);

    QChartView *chartViewYearsWithHypertension = new QChartView(chartYearsWithHypertension);
    chartViewYearsWithHypertension->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewYearsWithHypertension, 1, 0);






    //count of deceased patients with diabetes type 1 and diabetes type 2--------------------query1
    QSqlQueryModel diabetesType1;
    diabetesType1.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'On Treatment' && patient.Diabetes_type1 = 1;");
    int type1 = diabetesType1.data(diabetesType1.index(0, 0)).toInt();

    //count of patients with urinating problems--------------------query2
    QSqlQueryModel diabetesType2;
    diabetesType2.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'On Treatment' && patient.Diabetes_type2 = 1;");
    int type2 = diabetesType2.data(diabetesType2.index(0, 0)).toInt();


    //count of patients with high blood pressure--------------------query3
    QSqlQueryModel highBloodPressure;
    highBloodPressure.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'On Treatment' && patient.Blood_sugar > 130;");
    int bloodPressure = highBloodPressure.data(highBloodPressure.index(0, 0)).toInt();


    //count of patients with urinating problems--------------------query4
    QSqlQueryModel urinatingProblems;
    urinatingProblems.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'On Treatment' && patient.Urinating_problems = 1;");
    int urinationP = urinatingProblems.data(urinatingProblems.index(0, 0)).toInt();


    chartDisplay->ui->labelDiabetesType1->setText(QString(tr("Type 1 Diabetes count: %1")).arg(type1));

    chartDisplay->ui->labelDiabetesType2->setText(QString(tr("Type 2 Diabetes count: %1")).arg(type2));


    chartDisplay->ui->labelHIghBloodPressure->setText(QString(tr("High Blood Pressure count: %1")).arg(bloodPressure));

    chartDisplay->ui->labelUrinatingProblems->setText(QString(tr("Urination Problems count: %1")).arg(urinationP));



    chartDisplay->setWindowFlag(Qt::Window);
    chartDisplay->show();
}

void PatientReports::generatePatientsNeedingBloodReport()
{
    patientReportsDisplay * chartDisplay = new patientReportsDisplay(this);

    //graph of male and female deceased patients with a specific blood type------------------------GRAPH1
    vector<int>bloodtypeCounts;

    //--males of blood type A+
    QSqlQueryModel male_Aplus;
    male_Aplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.BloodType_id = 'A+';");
    int male_Apositive = male_Aplus.data(male_Aplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Apositive);
    //--females of blood type A+
    QSqlQueryModel female_Aplus;
    female_Aplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.BloodType_id = 'A+';");
    int female_Apositive = female_Aplus.data(female_Aplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Apositive);

    //--males of blood type A-
    QSqlQueryModel male_Aminus;
    male_Aminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.BloodType_id = 'A-';");
    int male_Anegative = male_Aminus.data(male_Aminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Anegative);
    //--females of blood type A-
    QSqlQueryModel female_Aminus;
    female_Aminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.BloodType_id = 'A-';");
    int female_Anegative = female_Aminus.data(female_Aminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Anegative);

    //--males of blood type B+
    QSqlQueryModel male_Bplus;
    male_Bplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.BloodType_id = 'B+';");
    int male_Bpositive = male_Bplus.data(male_Bplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Bpositive);
    //--females of blood type B+
    QSqlQueryModel female_Bplus;
    female_Bplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.BloodType_id = 'B+';");
    int female_Bpositive = female_Bplus.data(female_Bplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Bpositive);

    //--males of blood type B-
    QSqlQueryModel male_Bminus;
    male_Bminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.BloodType_id = 'B-';");
    int male_Bnegative = male_Bminus.data(male_Bminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Bnegative);
    //--females of blood type B-
    QSqlQueryModel female_Bminus;
    female_Bminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.BloodType_id = 'B-';");
    int female_Bnegative = female_Bminus.data(female_Bminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Bnegative);

    //--males of blood type AB+
    QSqlQueryModel male_ABplus;
    male_ABplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.BloodType_id = 'AB+';");
    int male_ABpositive = male_ABplus.data(male_ABplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_ABpositive);
    //--females of blood type AB+
    QSqlQueryModel female_ABplus;
    female_ABplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.BloodType_id = 'AB+';");
    int female_ABpositive = female_ABplus.data(female_ABplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_ABpositive);

    //--males of blood type AB-
    QSqlQueryModel male_ABminus;
    male_ABminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.BloodType_id = 'AB-';");
    int male_ABnegative = male_ABminus.data(male_ABminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_ABnegative);
    //--females of blood type AB-
    QSqlQueryModel female_ABminus;
    female_ABminus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.BloodType_id = 'AB-';");
    int female_ABnegative = female_ABminus.data(female_ABminus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_ABnegative);

    //--males of blood type O+
    QSqlQueryModel male_Oplus;
    male_Oplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.BloodType_id = 'O+';");
    int male_Opositive = male_Oplus.data(male_Oplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Opositive);
    //--females of blood type O+
    QSqlQueryModel female_Oplus;
    female_Oplus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.BloodType_id = 'O+';");
    int female_Opositive = female_Oplus.data(female_Oplus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Opositive);

    //--males of blood type O-
    QSqlQueryModel male_Ominus;
    male_Ominus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.BloodType_id = 'O-';");
    int male_Onegative = male_Ominus.data(male_Ominus.index(0, 0)).toInt(); bloodtypeCounts.push_back(male_Onegative);
    //--females of blood type O-
    QSqlQueryModel female_Ominus;
    female_Ominus.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.BloodType_id = 'O-';");
    int female_Onegative = female_Ominus.data(female_Ominus.index(0, 0)).toInt(); bloodtypeCounts.push_back(female_Onegative);


    QBarSet *bloodTypeMales = new QBarSet(tr("Male"));
    QBarSet *bloodTypeFemales = new QBarSet(tr("Female"));

    *bloodTypeMales << male_Apositive << male_Anegative << male_Bpositive << male_Bnegative <<  male_ABpositive << male_ABnegative << male_Opositive << male_Onegative;
    *bloodTypeFemales << female_Apositive << female_Anegative << female_Bpositive << female_Bnegative <<  female_ABpositive << female_ABnegative << female_Opositive << female_Onegative;

    QBarSeries *seriesBloodType = new QBarSeries();
    seriesBloodType->append(bloodTypeMales);
    seriesBloodType->append(bloodTypeFemales);

    QChart *chartBloodTypes = new QChart();
    chartBloodTypes->addSeries(seriesBloodType);
    chartBloodTypes->setTitle(tr("'In need of Blood' Patients BloodTypes"));
    chartBloodTypes->setAnimationOptions(QChart::SeriesAnimations);

    chartBloodTypes->legend()->setVisible(true); //setVisible
    chartBloodTypes->legend()->setAlignment(Qt::AlignBottom);

    QStringList categoriesBloodTypes;
    categoriesBloodTypes << "A+" << "A-" << "B+" << "B-" << "AB+" << "AB-" << "O+" << "O-";
    QBarCategoryAxis *axisXBloodTypeChart = new QBarCategoryAxis();
    axisXBloodTypeChart->append(categoriesBloodTypes);
    chartBloodTypes->addAxis(axisXBloodTypeChart, Qt::AlignBottom);
    seriesBloodType->attachAxis(axisXBloodTypeChart);

    QValueAxis *axisYBloodTypeChart = new QValueAxis();
    axisYBloodTypeChart->setRange(0, *max_element(bloodtypeCounts.begin(), bloodtypeCounts.end()));
    chartBloodTypes->addAxis(axisYBloodTypeChart, Qt::AlignLeft);
    seriesBloodType->attachAxis(axisYBloodTypeChart);

    QChartView *chartViewBloodType = new QChartView(chartBloodTypes);
    chartViewBloodType->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewBloodType, 0, 0);



    //graph of male and female deceased patients living in different districts---------------------GRAPH2
    vector<int>districtCounts;

    //--males living in Corozal
    QSqlQueryModel male_Corozal;
    male_Corozal.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.District = 'Corozal';");
    int male_corozalresident = male_Corozal.data(male_Corozal.index(0, 0)).toInt(); districtCounts.push_back(male_corozalresident);
    //--females living in Corozal
    QSqlQueryModel female_Corozal;
    female_Corozal.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.District = 'Corozal';");
    int female_corozalresident = female_Corozal.data(female_Corozal.index(0, 0)).toInt(); districtCounts.push_back(female_corozalresident);

    //--males living in Orange Walk
    QSqlQueryModel male_OrangeWalk;
    male_OrangeWalk.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.District = 'Orange Walk';");
    int male_owresident = male_OrangeWalk.data(male_OrangeWalk.index(0, 0)).toInt(); districtCounts.push_back(male_owresident);
    //--females living in Orange Walk
    QSqlQueryModel female_OrangeWalk;
    female_OrangeWalk.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.District = 'Orange Walk';");
    int female_owresident = female_OrangeWalk.data(female_OrangeWalk.index(0, 0)).toInt(); districtCounts.push_back(female_owresident);

    //--males living in Belize
    QSqlQueryModel male_Belize;
    male_Belize.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.District = 'Belize';");
    int male_belizeresident = male_Belize.data(male_Belize.index(0, 0)).toInt(); districtCounts.push_back(male_belizeresident);
    //--females living in Belize
    QSqlQueryModel female_Belize;
    female_Belize.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.District = 'Belize';");
    int female_belizeresident = female_Belize.data(female_Belize.index(0, 0)).toInt(); districtCounts.push_back(female_belizeresident);

    //--males living in Cayo
    QSqlQueryModel male_Cayo;
    male_Cayo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.District = 'Cayo';");
    int male_cayoresident = male_Cayo.data(male_Cayo.index(0, 0)).toInt(); districtCounts.push_back(male_cayoresident);
    //--females living in Cayo
    QSqlQueryModel female_Cayo;
    female_Cayo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.District = 'Cayo';");
    int female_cayoresident = female_Cayo.data(female_Cayo.index(0, 0)).toInt(); districtCounts.push_back(female_cayoresident);

    //--males living in Stann Creek
    QSqlQueryModel male_StannCreek;
    male_StannCreek.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.District = 'Stann Creek';");
    int male_stanncreekresident = male_StannCreek.data(male_StannCreek.index(0, 0)).toInt(); districtCounts.push_back(male_stanncreekresident);
    //--females living in Stann Creek
    QSqlQueryModel female_StannCreek;
    female_StannCreek.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.District = 'Stann Creek';");
    int female_stanncreekresident = female_StannCreek.data(female_StannCreek.index(0, 0)).toInt(); districtCounts.push_back(female_stanncreekresident);

    //--males living in Stann Creek
    QSqlQueryModel male_Toledo;
    male_Toledo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Male' && patient.District = 'Toledo';");
    int male_toledoresident = male_Toledo.data(male_Toledo.index(0, 0)).toInt(); districtCounts.push_back(male_toledoresident);
    //--females living in Stann Creek
    QSqlQueryModel female_Toledo;
    female_Toledo.setQuery("SELECT COUNT(*) FROM `patient` WHERE patient.Patient_status = 'In need of Blood' && patient.Gender = 'Female' && patient.District = 'Toledo';");
    int female_toledoresident = female_Toledo.data(female_Toledo.index(0, 0)).toInt(); districtCounts.push_back(female_toledoresident);


    QBarSet *districtMales = new QBarSet(tr("Male"));
    QBarSet *districtFemales = new QBarSet(tr("Female"));
    *districtMales << male_corozalresident << male_owresident << male_belizeresident << male_cayoresident << male_stanncreekresident << male_toledoresident;
    *districtFemales << female_corozalresident << female_owresident <<  female_belizeresident << female_cayoresident << female_stanncreekresident << female_toledoresident;

    QBarSeries *seriesDistricts = new QBarSeries();
    seriesDistricts->append(districtMales);
    seriesDistricts->append(districtFemales);

    QChart *chartDistricts = new QChart();
    chartDistricts->addSeries(seriesDistricts);
    chartDistricts->setTitle(tr("'In need of Blood' Patients District Location"));
    chartDistricts->setAnimationOptions(QChart::SeriesAnimations);

    chartDistricts->legend()->setVisible(true); //setVisible(true)
    chartDistricts->legend()->setAlignment(Qt::AlignBottom);

    QStringList categoriesDistricts;
    categoriesDistricts << "Corozal" << "Orange Walk" << "Belize" << "Cayo" << "Stann Creek" << "Toledo" ;
    QBarCategoryAxis *axisXDistrictChart = new QBarCategoryAxis();
    axisXDistrictChart->append(categoriesDistricts);
    chartDistricts->addAxis(axisXDistrictChart, Qt::AlignBottom);
    seriesDistricts->attachAxis(axisXDistrictChart);

    QValueAxis *axisYDistrictChart = new QValueAxis();
    axisYDistrictChart->setRange(0, *max_element(districtCounts.begin(), districtCounts.end()));
    chartDistricts->addAxis(axisYDistrictChart, Qt::AlignLeft);
    seriesDistricts->attachAxis(axisYDistrictChart);

    QChartView *chartViewDistricts = new QChartView(chartDistricts);
    chartViewDistricts->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewDistricts, 0, 1);


    qDebug()<<"A+ Male count " << male_Apositive << "and female is" << female_Apositive;
    qDebug()<<"A- Male count " << male_Anegative << "and female is" << female_Anegative;
    qDebug()<<"B+ Male count " << male_Bpositive << "and female is" << female_Bpositive;
    qDebug()<<"B- Male count " << male_Bnegative << "and female is" << female_Bnegative;
    qDebug()<<"AB+ Male count " << male_ABpositive << "and female is" << female_ABpositive;
    qDebug()<<"AB- Male count " << male_ABnegative << "and female is" << female_ABnegative;
    qDebug()<<"O+ Male count " << male_Opositive << "and female is" << female_Opositive ;
    qDebug()<<"O- Male count " << male_Onegative << "and female is" << female_Onegative;

    qDebug()<< "Corozal female count " << female_corozalresident <<  " and male is  "  << male_corozalresident;
    qDebug()<< "Orange Walk female count " << female_owresident << " and male is  "  << male_owresident;
    qDebug()<< "Belize female count " << female_belizeresident << " and male is  "  << male_belizeresident;
    qDebug()<< "Cayo female count " << female_cayoresident << " and male is  "  << male_cayoresident;
    qDebug()<< "Stann Creek female count " << female_stanncreekresident << " and male is  "  << male_stanncreekresident;
    qDebug()<< "Toledo female count " << female_toledoresident << " and male is  "  << male_toledoresident;


    //graph of the numbers of year frequencies deceased patients have had diabetes---------------------GRAPH3
    vector<int>years;
    vector<int>frequencies;

    QSqlQuery yearsWithDiabetes("SELECT patient.Years_with_diabetes, COUNT(patient.Years_with_diabetes)AS Frequency FROM patient WHERE patient.Patient_status = 'In need of Blood' GROUP BY patient.Years_with_diabetes ORDER BY COUNT(patient.Years_with_diabetes) DESC;");
    int col_1 = yearsWithDiabetes.record().indexOf("Years_with_diabetes");
    int col_2 = yearsWithDiabetes.record().indexOf("Frequency");
    while (yearsWithDiabetes.next()) {
        years.push_back(yearsWithDiabetes.value(col_1).toInt());
        frequencies.push_back(yearsWithDiabetes.value(col_2).toInt());
    }
    //list of years and their frequencies to which they occur are saved

    QPieSeries *seriesYearsWithDiabetes= new QPieSeries();

    int check = 0;

    for(int i = 0; i < years.size(); i++){
        if(years[i] == 0){
            continue;
        }else{
            check++;
            seriesYearsWithDiabetes->append(QString::number(years[i]), frequencies[i]);
        }
    }

    try{
        if(check != 0){
            QPieSlice *sliceYearsWithDiabetes = seriesYearsWithDiabetes->slices().at(0);
            sliceYearsWithDiabetes->setExploded();
            sliceYearsWithDiabetes->setLabelVisible();
            sliceYearsWithDiabetes->setPen(QPen(Qt::red, 2));
            sliceYearsWithDiabetes->setBrush(Qt::red);
        }
    }catch(...){
        qDebug()<<"error on line 1053 in patientreports.cpp";
    }

    QChart *chartYearsWithDiabetes = new QChart();
    chartYearsWithDiabetes->addSeries(seriesYearsWithDiabetes);
    chartYearsWithDiabetes->setTitle(tr("Frequency of years that 'In need of Blood' patients had Diabetes"));
    chartYearsWithDiabetes->legend()->setVisible(true);

    QChartView *chartViewYearsWithDiabetes = new QChartView(chartYearsWithDiabetes);
    chartViewYearsWithDiabetes->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewYearsWithDiabetes, 1, 1);


    //graph of the numbers of years deceased patients have had hypertension---------------------GRAPH4
    years.clear();
    frequencies.clear();

    QSqlQuery yearsWithHypertension("SELECT patient.Years_with_hypertension, COUNT(patient.Years_with_hypertension)AS Frequency FROM patient WHERE patient.Patient_status = 'In need of Blood' GROUP BY patient.Years_with_hypertension ORDER BY COUNT(patient.Years_with_hypertension) DESC;");
    col_1 = yearsWithHypertension.record().indexOf("Years_with_hypertension");
    col_2 = yearsWithHypertension.record().indexOf("Frequency");
    while (yearsWithHypertension.next()) {
        years.push_back(yearsWithHypertension.value(col_1).toInt());
        frequencies.push_back(yearsWithHypertension.value(col_2).toInt());
    }
    //list of years and their frequencies to which they occur are saved

    QPieSeries *seriesYearsWithHypertension = new QPieSeries();

    check = 0;
    for(int i = 0; i < years.size(); i++){
        if(years[i] == 0){
            continue;
        }else{
            check++;
            seriesYearsWithHypertension->append(QString::number(years[i]), frequencies[i]);
        }
    }

    try{
        if(check != 0){
            QPieSlice *sliceYearsWithHypertension = seriesYearsWithHypertension->slices().at(0);
            sliceYearsWithHypertension->setExploded();
            sliceYearsWithHypertension->setLabelVisible();
            sliceYearsWithHypertension->setPen(QPen(Qt::red, 2));
            sliceYearsWithHypertension->setBrush(Qt::red);
        }
    }catch(...){
        qDebug()<< "error on line 1101 in patientreports.cpp";
    }

    QChart *chartYearsWithHypertension = new QChart();
    chartYearsWithHypertension->addSeries(seriesYearsWithHypertension);
    chartYearsWithHypertension->setTitle(tr("Frequency of years that 'In need of Blood' patients had Hypertension"));
    chartYearsWithHypertension->legend()->setVisible(true);

    QChartView *chartViewYearsWithHypertension = new QChartView(chartYearsWithHypertension);
    chartViewYearsWithHypertension->setRenderHint(QPainter::Antialiasing);

    chartDisplay->ui->gridLayout->addWidget(chartViewYearsWithHypertension, 1, 0);






    //count of deceased patients with diabetes type 1 and diabetes type 2--------------------query1
    QSqlQueryModel diabetesType1;
    diabetesType1.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'In need of Blood' && patient.Diabetes_type1 = 1;");
    int type1 = diabetesType1.data(diabetesType1.index(0, 0)).toInt();

    //count of patients with urinating problems--------------------query2
    QSqlQueryModel diabetesType2;
    diabetesType2.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'In need of Blood' && patient.Diabetes_type2 = 1;");
    int type2 = diabetesType2.data(diabetesType2.index(0, 0)).toInt();


    //count of patients with high blood pressure--------------------query3
    QSqlQueryModel highBloodPressure;
    highBloodPressure.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'In need of Blood' && patient.Blood_sugar > 130;");
    int bloodPressure = highBloodPressure.data(highBloodPressure.index(0, 0)).toInt();


    //count of patients with urinating problems--------------------query4
    QSqlQueryModel urinatingProblems;
    urinatingProblems.setQuery("SELECT COUNT(*) FROM patient WHERE patient.Patient_status = 'In need of Blood' && patient.Urinating_problems = 1;");
    int urinationP = urinatingProblems.data(urinatingProblems.index(0, 0)).toInt();


    chartDisplay->ui->labelDiabetesType1->setText(QString(tr("Type 1 Diabetes count: %1")).arg(type1));

    chartDisplay->ui->labelDiabetesType2->setText(QString(tr("Type 2 Diabetes count: %1")).arg(type2));


    chartDisplay->ui->labelHIghBloodPressure->setText(QString(tr("High Blood Pressure count: %1")).arg(bloodPressure));

    chartDisplay->ui->labelUrinatingProblems->setText(QString(tr("Urination Problems count: %1")).arg(urinationP));



    chartDisplay->setWindowFlag(Qt::Window);
    chartDisplay->show();
}
