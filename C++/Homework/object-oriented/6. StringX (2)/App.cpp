﻿#include "App.h"

#include <iostream>
#include <string>

using namespace std;


/*
    
    -- Добавлена перегрузка трёх методов: Concatination (merge) - "+", Split - "/" и Contains - "%". (см. region "Task Demonstration")


*/

#define demo_one demoStringOne // Имя объекта для демонстрации
#define demo_two demoStringTwo // Второй объект, необходимый для демонстрации
#define demo_three demoStringThree // Третий объект, необходимый для демонстрации
#define INDEX 48 // Номер единицы в табице чаров

#define space std::cout << "\n\n"
#define tab std::cout<<"\t"



#pragma region OBJECTIVE

/*

    Дополнить класс String перегрузками операций.

 - Придумать и реализовать перегрузки операций для методов concat, split, contains.


*/

#pragma endregion OBJECTIVE




#pragma region CONSTRUCT


App::App()
{

}


#pragma endregion CONSTRUCT





void App::run()
{
    

#pragma region PREPARATIONS


    StringEx demo_one("Hello");

    StringEx demo_two("_");

    StringEx demo_three("World!");


#pragma endregion PREPARATIONS






#pragma region MENU_LOOP


    int i = 0;

    char c_cont = 'y';

    while (c_cont != 'n' && c_cont != 'N')
    {
        drawMenuStart();
        i = selector(5);

        switch (i)
        {
        case 1:
            drawConcatenation(demo_one, demo_two, demo_three);
            break;
        case 2:
            drawSplit(demo_one, demo_two, demo_three);
            break;
        case 3:
            drawInsert(demo_one);
            break;
        case 4:
            drawContains(demo_one, demo_two);
            break;
        case 5:
            system("cls");
            space;
            std::cout << "\t\tYou've quit! Have a nice day!\n\t\t(Press any key) .....";
            space;
            return;
        default:
            break;
        }
        space;
        showContinue();
        c_cont = _getwch();
        system("cls");
    }
    space;
    std::cout << "\t\tYou've quit! Have a nice day!\n\t\t(Press any key) .....";
    space;


#pragma endregion MENU_LOOP
}




#pragma region TASK_DEMONSTRATION


void App::drawConcatenation(StringEx& demo_one, StringEx& demo_two, StringEx& demo_three)
{


#pragma region DRAWING_1

    demo_one.setString("Hello");

    demo_two.setString("_");

    demo_three.setString("World!");

    space;
    space;
    tab;
    std::cout << "There are three objects:";
    space;
    space;
    tab;
    std::cout << " > demo_one is \"";

    for (int i = 0; i < demo_one.getLength(); i++)
    {
        std::cout << demo_one.getArrayPtr()[i];
    }

    std::cout << "\"";
    space;
    tab;
    std::cout << " > demo_two is \"";

    for (int i = 0; i < demo_two.getLength(); i++)
    {
        std::cout << demo_two.getArrayPtr()[i];
    }

    std::cout << "\"";
    space;
    tab;
    std::cout << " > demo_three is \"";

    for (int i = 0; i < demo_three.getLength(); i++)
    {
        std::cout << demo_three.getArrayPtr()[i];
    }
    std::cout << "\"";

    space;
    space;
    tab;
    std::cout << "Combining 1 with 2:";

#pragma endregion DRAWING_1

    demo_one + demo_two; // =======================================


#pragma region DRAWING_2
    tab;
    tab;
    
    for (int i = 0; i < demo_one.getLength(); i++)
    {
        std::cout << demo_one.getArrayPtr()[i];
    }

    space;
    tab;
    std::cout << "Combining 1 and 2 with 3:";
#pragma endregion DRAWING_2


    demo_one + demo_three; // =====================================


#pragma region DRAWING_3
    tab;

    for (int i = 0; i < demo_one.getLength(); i++)
    {
        std::cout << demo_one.getArrayPtr()[i];
    }

    space;
    space;
#pragma endregion DRAWING_3


}


void App::drawSplit(StringEx& demo_one, StringEx& demo_two, StringEx& demo_three)
{


#pragma region DRAWING_1
    space;
    space;
    tab;
    demo_one.setString("Hello_World!");
    std::cout << "There is an object:";
    space;
    tab;
    std::cout << " > demo_one is \"";

    for (int i = 0; i < demo_one.getLength(); i++)
    {
        std::cout << demo_one.getArrayPtr()[i];
    }

    std::cout << "\"";

    space;
    space;
    tab;
    std::cout << "Now, this object has been split into:";
#pragma endregion DRAWING_1


    StringEx* demo_ptr = demo_one / '_'; // ================================


#pragma region DRAWING_2
    
    demo_two = demo_ptr[0];

    demo_three = demo_ptr[1];

    space;
    tab;
    std::cout << " > demo_two is \"";

    for (int i = 0; i < demo_two.getLength(); i++)
    {
        std::cout << demo_two.getArrayPtr()[i];
    }

    std::cout << "\"";
    space;
    tab;
    std::cout << " > demo_three is \"";

    for (int i = 0; i < demo_three.getLength(); i++)
    {
        std::cout << demo_three.getArrayPtr()[i];
    }
    std::cout << "\"";

    space;
    space;

#pragma endregion DRAWING_2


}


void App::drawInsert(StringEx& demo_one)
{
    space;
    space;
    tab;
    demo_one.setString("Hello_World!");
    std::cout << "There is an object:";
    space;
    tab;
    std::cout << " > demo_one is \"";

    for (int i = 0; i < demo_one.getLength(); i++)
    {
        std::cout << demo_one.getArrayPtr()[i];
    }

    std::cout << "\"";

    space;
    space;
    tab;
    std::cout << "Now, We'll insert a hash symbol (\"#\") after each other symbols:";

    space;
    space;
    tab;

    int length = demo_one.getLength();
    for (int i = 1; i < length * 2; i += 2)
    {
        demo_one.insert("#", i);
    }


    std::cout << "Result:";
    space;
    tab;
    std::cout << " > demo_one is \"";

    for (int i = 0; i < demo_one.getLength(); i++)
    {
        std::cout << demo_one.getArrayPtr()[i];
    }

    std::cout << "\"";

    space;
    space;
}


void App::drawContains(StringEx& demo_one, StringEx& demo_two)
{


#pragma region DRAWING_1

    demo_two.setString("_");

    space;
    space;
    tab;
    demo_one.setString("Hello_World!");
    std::cout << "There are two objects:";
    space;
    tab;
    std::cout << " > demo_one is \"";

    for (int i = 0; i < demo_one.getLength(); i++)
    {
        std::cout << demo_one.getArrayPtr()[i];
    }

    std::cout << "\"";

    space;
    tab;
    std::cout << " > demo_two is \"";

    for (int i = 0; i < demo_two.getLength(); i++)
    {
        std::cout << demo_two.getArrayPtr()[i];
    }

    std::cout << "\"";

    space;
    space;

    tab;
    std::cout << "Checking for containment of Char \"#\" in demo_one:";
    std::cout << "\n\tResult:\t";
#pragma endregion DRAWING_1

    int l = demo_one % "#"; // По какой-то причине, с перегрузкой перестаёт работать оператор "<<"
    std::cout << l;


#pragma region DRAWING_2
    space;

    tab;
    std::cout << "Checking for containment of Const Char* \"ell\" in demo_one:";
    std::cout << "\n\tResult:\t";
#pragma endregion DRAWING_2

    l = demo_one % "ell"; // По какой-то причине, с перегрузкой перестаёт работать оператор "<<"
    std::cout << l;


#pragma region DRAWING_3
    space;

    tab;
    std::cout << "Checking for containment of another StringEx <demo_two> in demo_one:";
    std::cout << "\n\tResult:\t";
#pragma endregion DRAWING_3

    l = demo_one % (demo_two.getArrayPtr());            // Дебажил полдня, так и не понял, по какой именно причине при передаче строки типа
    std::cout << l;                                     // StringEx в перегруженный метод contains(), вместо contains() компайлер попадает
                                                        // в конструктор копирования, а затем выбрасывает bad alloc эксепшн при том,
                                                        // что сам метод contains() работает нормально. Постараюсь разобраться
#pragma region REST

    space;
    space;

#pragma endregion REST
}


#pragma endregion TASK_DEMONSTRATION




#pragma region MENU_DRAWING


void App::showContinue()
{
    const int len = 47;
    std::cout << "\t" << char(201);
    for (int i = 0; i < len; i++)
    {
        std::cout << char(205);
    }
    std::cout << char(187);
    std::cout << "\n\t" << char(186);

    std::cout << "  Do you want to continue the programme? (y/n) ";

    std::cout << char(186) << "\n";
    std::cout << "\t" << char(200);
    for (int i = 0; i < len; i++)
    {
        std::cout << char(205);
    }
    std::cout << char(188) << "\n";
}


void App::drawMenuStart()
{
    space;
    space;
    tab;
    std::cout << "Choose an action:";
    space;
    tab;
    std::cout << "1. Concatenation\n\t";
    std::cout << "2. Split\n\t";
    std::cout << "3. Insert\n\t";
    std::cout << "4. Contains\n\t";
    std::cout << "5. Exit";
    space;
}


int App::selector(int nOptionsQuantity)
{
    char user;
    do
    {
        user = _getwch();
    } while ((int)user < INDEX && (int)user > INDEX + nOptionsQuantity); // Пока ввод пользователя меньше 1 или больше кол-ва вариантов в меню

    return (int)user - INDEX;

}


#pragma endregion MENU_DRAWING

