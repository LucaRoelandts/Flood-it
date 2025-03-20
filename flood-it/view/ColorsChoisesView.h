#ifndef COLORSCHOISESVIEW_H
#define COLORSCHOISESVIEW_H
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "../model/Colors.h"
class ColorsChoisesView : public QWidget{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de ColorsChoicesView.
     * @param colors Liste des couleurs disponibles.
     * @param parent Widget parent.
     */
    explicit ColorsChoisesView(const std::vector<Colors>& colors, QWidget *parent = nullptr);
    ColorsChoisesView(QWidget *parent=nullptr);
private:
    QGridLayout _layout;
    std::vector<QPushButton *> _buttons;

};

#endif // COLORSCHOISESVIEW_H
