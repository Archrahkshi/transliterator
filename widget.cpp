#include <unicode/translit.h>

#include "widget.hpp"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

using namespace icu;

UnicodeString rulesRO{ // Romanian. Also possible: Kurdish, Turkish
        "a > а;"                                                                    "A > А;"
        "ă > э;"                                                                    "Ă > Э;"
        "â > ы;"                                                                    "Â > Ы;"
        "b > б;"                                                                    "B > Б;"
        "c[ei]a > ча;"                                                              "C[ei]a > Ча;"
        "cio > чо;"                                                                 "Cio > Чо;"
        "ciu > чу;"                                                                 "Ciu > Чу;"
        "ci } [:^Letter:] > ч;"                                                     "Сi } [:^Letter:] > Ч;"
        "ch } [ei] > к;"                                                            "Ch } [ei] > К;"
        "c } [ei] > с;"                                                             "C } [ei] > С;"
        "c > к;"                                                                    "C > К;"
        "d > д;"                                                                    "D > Д;"
        "ea > я;"                                                                   "Ea > Я;"
        "[:^Letter:] { e > э;"                                                     "[:^Letter:] { E > Э;"
        "e > е;"                                                                    "E > е;"
        "f > ф;"                                                                    "F > Ф;"
        "g[ei]a > джа;"                                                             "G[ei]a > Джа;"
        "g[ei]o > джо;"                                                             "G[ei]o > Джо;"
        "gh > г;"                                                                   "Gh > Г;"
        "giu > джу;"                                                                "Giu > Джу;"
        "g } [ei] > дж;"                                                            "G } [ei] > Дж;"
        "g > г;"                                                                    "G > Г;"
        "h > х;"                                                                    "H > Х;"
        "[[:^Letter:][aăâeiîouyAĂÂEIÎOUY]] { ia > я;"                               "Ia > Я;"
        "[bcdfghjklmnpqrsștțvwxzBCDFGHJKLMNPQRSȘTȚVWXZ] { ia } [:Letter:] > ья;"
        "ia } [:^Letter:] > ия;"
        "[:^Letter:] { ie > е;"                                                     "Ie > е;"
        "[aăâeiîouyAĂÂEIÎOUY] { ie > е;"
        "[bcdfghjklmnpqrsștțvwxzBCDFGHJKLMNPQRSȘTȚVWXZ] { ie } [:Letter:] > ье;"
        "ie } [:^Letter:] > ие;"
        "ii } [:^Letter:] > и;"
        "[[:^Letter:][aăâeiîouyAĂÂEIÎOUY]] { io > йо;"
        "[bcdfghjklmnpqrsștțvwxzBCDFGHJKLMNPQRSȘTȚVWXZ] { io } [:Letter:] > ьо;"
        "[[:^Letter:][aăâeiîouyAĂÂEIÎOUY]] { iu > ю;"
        "[bcdfghjklmnpqrsștțvwxzBCDFGHJKLMNPQRSȘTȚVWXZ] { iu } [:Letter:] > ью;"
        "[bcdfghjklmnpqrsștțvwxzBCDFGHJKLMNPQRSȘTȚVWXZ] { iu } [:^Letter:] > иу;"
        "[aăâeîouyAĂÂEÎOUY] { i > й;"
        "i > и;"                                                                    "I > И;"
        "îi > ый;"                                                                  "Îi > Ый;"
        "[:^Letter:] { î > и;"                                                      "Î > И;"
        "[:Letter:] { î } [:Letter:] > ы;"
        "j > ж;"                                                                    "J > Ж;"
        "k > к;"                                                                    "K > К;"
        "l > л;"                                                                    "L > Л;"
        "m > м;"                                                                    "M > М;"
        "n > н;"                                                                    "N > Н;"
        "o > о;"                                                                    "O > О;"
        "p > п;"                                                                    "P > П;"
        "q > к;"                                                                    "Q > К;"
        "r > р;"                                                                    "R > Р;"
        "s } [bdglmv] > з;"                                                         "S } [bdglmv] > З;"
        "s > с;"                                                                    "S > С;"
        "ș > ш;"                                                                    "Ș > Ш;"
        "t > т;"                                                                    "T > Т;"
        "ț > ц;"                                                                    "Ț > Ц;"
        "i { u } [:^Letter:] > ;"
        "u > у;"                                                                    "U > У;"
        "v > в;"                                                                    "V > В;"
        "w > в;"                                                                    "W > В;"
        "x > кс;"                                                                   "X > Кс;"
        "y } [aăâeiîouy] > й;"                                                      "Y } [aăâeiîouy] > Й;"
        "y > и;"                                                                    "Y > И;"
        "z > з;"                                                                    "Z > З;"
        };
UnicodeString rulesSL{ // Slovene
    "a > а;"                                                "A > А;"
    "b > б;"                                                "B > Б;"
    "c > ц;"                                                "C > Ц;"
    "č > ч;"                                                "Č > Ч;"
    "dž > дж;"                                              "Dž > Дж;"
    "d > д;"                                                "D > Д;"
    "[aeiouAEIOU] { e > э;"                                 "E > Э;"
    "[bcčdfghklmnprsštvzžBCČDFGHKLMNPRSŠTVZŽ] { e > е;"
    "f > ф;"                                                "F > Ф;"
    "g > г;"                                                "G > Г;"
    "h > х;"                                                "H > Х;"
    "i > и;"                                                "I > И;"
    "[aeiouAEIOU] { ja > я;"                                "Ja > Я;"
    "[aeiouAEIOU] { je > е;"                                "Je > Е;"
    "[aeiouAEIOU] { jo > йо;"                               "Jo > Йо;"
    "[aeiouAEIOU] { ju > ю;"                                "Ju > Ю;"
    "[bcčdfghklmnprsštvzžBCČDFGHKLMNPRSŠTVZŽ] { ja > ья;"
    "[bcčdfghklmnprsštvzžBCČDFGHKLMNPRSŠTVZŽ] { je > ье;"
    "[bcčdfghklmnprsštvzžBCČDFGHKLMNPRSŠTVZŽ] { ji > ьи;"
    "[bcčdfghklmnprsštvzžBCČDFGHKLMNPRSŠTVZŽ] { jo > ьо;"
    "[bcčdfghklmnprsštvzžBCČDFGHKLMNPRSŠTVZŽ] { ju > ью;"
    "j > й;"                                                "J > Й;"
    "k > к;"                                                "K > К;"
    "lja > ля;"                                             "Lja > Ля;"
    "lje > ле;"                                             "Lje > Ле;"
    "lji > ли;"                                             "Lji > Ли;"
    "ljo > лё;"                                             "Ljo > Лё;"
    "lju > лю;"                                             "Lju > Лю;"
    "lj > ль;"                                              "Lj > Ль;"
    "l > л;"                                                "L > Л;"
    "m > м;"                                                "M > М;"
    "nja > ня;"                                             "Nja > Ня;"
    "nje > не;"                                             "Nje > Не;"
    "nji > ни;"                                             "Nji > Ни;"
    "njo > нё;"                                             "Njo > Нё;"
    "nju > ню;"                                             "Nju > Ню;"
    "nj > нь;"                                              "Nj > Нь;"
    "n > н;"                                                "N > Н;"
    "o > о;"                                                "O > О;"
    "p > п;"                                                "P > П;"
    "r > р;"                                                "R > Р;"
    "s > с;"                                                "S > С;"
    "š > ш;"                                                "Š > Ш;"
    "t > т;"                                                "T > Т;"
    "u > у;"                                                "U > У;"
    "v > в;"                                                "V > В;"
    "z > з;"                                                "Z > З;"
    "ž > ж;"                                                "Ž > Ж;"
};

void Widget::on_lineEdit_returnPressed()
{
    UnicodeString in = ui->lineEdit->text().toStdString().c_str();

    UnicodeString rules;
    if(ui->radioButton->isChecked()) rules = rulesRO;
    else if(ui->radioButton_2->isChecked()) rules = rulesSL;

    Transliterator *rbt;
    UParseError pError; // Struct to receive information on position of error if encountered
    UErrorCode status = U_ZERO_ERROR;

    rbt = Transliterator::createFromRules("RU", rules, UTRANS_FORWARD, pError, status);
    rbt->transliterate(in);

    auto inLen = in.extract(0, in.length(), nullptr);
    std::string buf(inLen + 1, '\0');
    in.extract(0, in.length(), buf.data());
    buf.resize(inLen);
    QString out;

    ui->textBrowser->setText(out.fromStdString(buf));
}
