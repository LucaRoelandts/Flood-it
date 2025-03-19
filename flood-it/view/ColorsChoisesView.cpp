#include "ColorsChoisesView.h"

ColorsChoisesView::ColorsChoisesView(const std::vector<Colors>& colors, QWidget *parent):
    QWidget(parent),
    _layout(this),
    _buttons{}
{
    for(Colors color: colors) {
        QPushButton btn(this);
        btn.setStyleSheet(QString("border-radius: 25px; background-color: %1;")
                                   .arg(toQColor(color).name()));
        _buttons.push_back(btn);
    }
}
