#include "statanalysewidget.h"

StatAnalyseWidget::StatAnalyseWidget(FastqReader * reader,QWidget *parent)
    :AbstractAnalyseWidget(reader,parent)
{

    mView = new QTreeWidget;
    mView->setColumnCount(2);
    mView->setHeaderLabels(QStringList()<<"Measure"<<"Value");
    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mView);

    setLayout(mainLayout);

    setWindowTitle("Stat");
    setWindowIcon(QIcon::fromTheme("edit-undo"));

    connect(reader,&FastqReader::done, this, &StatAnalyseWidget::fill);

}

void StatAnalyseWidget::fill()
{



    addField("Total Sequences", QString::number(reader()->results().totalSequence));
    addField("Sequences length", QString::number(reader()->results().sequenceLength));



}

void StatAnalyseWidget::addField(const QString &label, const QString &value)
{

    QTreeWidgetItem * item =  new QTreeWidgetItem;
    item->setText(0, label);
    item->setText(1, value);
    mView->addTopLevelItem(item);

}