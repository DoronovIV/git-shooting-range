using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

using Tools.Formatting;

using Spectre.Console;


namespace Homework.NET
{

    public partial class Application
    {

        /// <summary>
        /// Integer 24 �����;
        /// 
        ///     ��� ������ ������������� ��������� �������: 0 � �����������,
        /// 1 � �����������, 2 � �������, . . . , 6 � �������. ���� ����� ����� K,
        /// ������� � ��������� 1�365. ���������� ����� ��� ������ ��� K-�� ���
        /// ����, ���� ��������, ��� � ���� ���� 1 ������ ���� �������������;
        /// 
        /// </summary>
        public void Integer24()
        {
            Console.WriteLine("\n");
            string sTaskSentense = "";
            sTaskSentense += ("\t��� ������ ������������� ��������� �������: 0 � �����������,\n");
            sTaskSentense += ("\t1 � �����������, 2 � �������, . . . , 6 � �������. ���� ����� ����� K,\n");
            sTaskSentense += ("\t������� � ��������� 1�365. ���������� ����� ��� ������ ��� K-�� ���\n");
            sTaskSentense += ("\t����, ���� ��������, ��� � ���� ���� 1 ������ ���� �������������;\n");

            Console.WriteLine(sTaskSentense);
            Console.WriteLine("\n");

            Console.Write("\tPlease, enter a number (1-365)\n\n\tYou: ");

            int nDayNumber = 0;

            try
            {
                nDayNumber = Int32.Parse(Console.ReadLine());
            }
            catch (FormatException e)
            {
                AnsiConsole.Write(new Markup("\n\t[red]Please, enter a digital number.[/]\n"));
                return;
            }

            Console.WriteLine("\n");

            while (nDayNumber > 6)
            {
                nDayNumber %= 6;
            }

            nDayNumber -= Toolbox.NUMERATION_ISSUE;

            Console.Write("\tThe day you entered is: ");

            switch (nDayNumber)
            {
                case 0:
                    Console.WriteLine("Sunday.");
                    break;
                case 1:
                    Console.WriteLine("Monday.");
                    break;
                case 2:
                    Console.WriteLine("Tuesday.");
                    break;
                case 3:
                    Console.WriteLine("Wednesday.");
                    break;
                case 4:
                    Console.WriteLine("Thursday.");
                    break;
                case 5:
                    Console.WriteLine("Friday.");
                    break;
                case 6:
                    Console.WriteLine("Saturday.");
                    break;
                default:
                    break;
            }

            Console.WriteLine("\n");
        }
    }

}