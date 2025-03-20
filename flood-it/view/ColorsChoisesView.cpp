#include "ColorsChoisesView.h"

ColorsChoisesView::ColorsChoisesView(const std::vector<Colors>& colors, QWidget *parent):
    QWidget(parent),
    _layout(this),
    _buttons{}
{
    for (int var = 0; var < colors.size(); ++var) {
        QPushButton *btn=new QPushButton(this);
        btn->setStyleSheet(QString("border-radius: 25px; background-color: %1;")
                               .arg(toQColor(colors.at(var)).name()));
        btn->setFixedSize(40,40);
        _buttons.push_back(btn);
        if(var<colors.size()/2)
            _layout.addWidget(btn,0,var);
        else
            _layout.addWidget(btn,1,var-colors.size()/2);
    }
    _layout.setSizeConstraint(QLayout::SetFixedSize);
    setLayout(&_layout);
}
ColorsChoisesView::ColorsChoisesView(QWidget *parent)
{

}
