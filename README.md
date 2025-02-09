# Cutting_plywood
Программа по расчету стоимости работы по резке фанеры

Представьте себе ситуацию: вы планируете проект, требующий использования фанеры, будь то ремонт, изготовление мебели или создание декоративных элементов. Вы сталкиваетесь с необходимостью рассчитать стоимость материала, работ по резке и абрису, а также учесть комиссию оператора на станке. Ручные вычисления занимают время, а риск ошибки в расчетах может привести к нежелательным финансовым последствиям.
Именно для решения этой задачи и создана данная программа. Она представляет собой инструмент для быстрого и точного расчета стоимости фанеры, учитывая все необходимые параметры.
Программа проста в использовании: вы выбираете тип фанеры (толщину) из списка, вводите необходимую длину резки и абриса, а также указываете, используете ли вы свой материал или покупаете его в магазине. Программное обеспечение автоматически вычисляет стоимость материала, работ и комиссии оператора, отображая результат в удобном виде.

---

##Графический интерфейс

Пользовательский интерфейс проекта создан на языке программирования С++ с использованием среды разработки VisualStudio на базе проекта CLR (.NET Framework) с использованием конструктора форм.

![image](https://github.com/Digital-Department-Vavilov-University/Cutting_plywood/assets/135830345/cca15944-8969-4c6d-9c18-0fa78f487c2c)

---

## Принцип работы кода

Структура Plywood

![image](https://github.com/Digital-Department-Vavilov-University/Cutting_plywood/assets/135830345/3298c376-e718-459c-9405-6888d992839b)

struct Plywood: Объявляет структуру данных с именем Plywood. Структуры в C++ используются для группировки данных, связанных с одним объектом.
int thickness: Целочисленное поле для хранения толщины фанеры (в миллиметрах).
double price: Поле с плавающей точкой для хранения цены листа фанеры (в рублях).
double cuttingPrice: Поле с плавающей точкой для хранения цены за резку одного метра фанеры (в рублях).
double abrisPrice: Поле с плавающей точкой для хранения цены за один метр абриса (в рублях).

Массив plywoodTypes

![image](https://github.com/Digital-Department-Vavilov-University/Cutting_plywood/assets/135830345/e17ce099-05ab-4ba0-9a04-5a3f4b7bbfdc)

Plywood plywoodTypes[]: Объявляет массив структур Plywood. Массив содержит информацию о различных типах фанеры.
{ 3, 700, 25, 10 }: Каждый элемент массива представляет один тип фанеры. В данном случае это:
3: Толщина фанеры (3 мм).
700: Цена листа фанеры (700 рублей).
25: Цена резки за метр (25 рублей).
10: Цена абриса за метр (10 рублей).
Другие элементы массива: Аналогично описывают информацию о других типах фанеры (4 мм, 6 мм, 8 мм).

Обработчик события calculateButton_Click

 ![image](https://github.com/Digital-Department-Vavilov-University/Cutting_plywood/assets/135830345/deda9d79-3dd8-4137-a425-3c59b9e7738b)

1.void calculateButton_Click(System::Object^ sender, System::EventArgs^ e): Этот метод вызывается, когда пользователь нажимает кнопку “Рассчитать”.
2.sender: Аргумент sender содержит ссылку на объект, который вызвал событие (в данном случае, кнопку calculateButton).
3.e: Аргумент e содержит информацию о событии (в данном случае, это просто событие клика).
__Внутри обработчика события calculateButton_Click происходит следующее:__

1.Выбор фанеры: Получается выбранный тип фанеры из комбобокса plywoodComboBox.
2.Проверка ввода: Проверяется, чтобы в текстовых полях lengthTextBox и abrisTextBox были введены значения, и они были корректными числами.
3.Расчет стоимости: Если ввод корректен, происходит расчет стоимости, включая цену листа, цену резки и цену абриса.
4.Обработка опции “свой материал”: Если выбрана опция “свой материал”, из стоимости вычитается цена листа.
5.Расчет комиссии оператора: Вычисляется комиссия оператора (15% от общей стоимости).
6.Обновление меток: Обновляется значение стоимости в метке priceLabel и значение комиссии оператора в метке operatorFeeLabel.

---

## Пример использования

1.Ставим галочку, если у вас свой материал

![image](https://github.com/Digital-Department-Vavilov-University/Cutting_plywood/assets/135830345/71208268-2a70-4e6e-bdef-acaddf9d8f54)

2.Заполняем данные по резке

![image](https://github.com/Digital-Department-Vavilov-University/Cutting_plywood/assets/135830345/0b1274bb-bd50-4ead-b54e-52afc5ceba9a)

3.Получаем результат по нажатию кнопки "Рассчиать"

![image](https://github.com/Digital-Department-Vavilov-University/Cutting_plywood/assets/135830345/cd8964b7-b4d3-4123-885d-6285af41dfc2)


### Стек технологий

__ОС__: Windows

__Язык__: C++

__Среда исполнения__: Microsoft VisualStudio C++ 2017 – 2024

