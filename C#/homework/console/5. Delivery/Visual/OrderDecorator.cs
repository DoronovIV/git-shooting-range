using System;

using Delivery.BaseClasses;

using Spectre.Console;

namespace Delivery.Visual
{
    /// <summary>
    /// Print order into console;
    /// <br />
    /// ���������� ����� � �������;
    /// </summary>
    public class OrderDecorator
    {


        #region PROPERTIES


        /// <summary>
        /// A reference to decorated order;
        /// <br />
        /// ������ �� ������������ �����;
        /// </summary>
        public Order OrderReference { get; set; }


        #endregion PROPERTIES



        #region CONSTRUCTION


        /// <summary>
        /// A reference to the order constructor;
        /// <br />
        /// ���������� �� ������� �� �����;
        /// </summary>
        /// <param name="oOrderReference">A reference to the order;<br />������ �� ������������ �����;</param>
        public OrderDecorator(Order oOrderReference)
        {
            OrderReference = oOrderReference;
        }


        #endregion CONSTRUCTION



        #region API


        /// <summary>
        /// Print order into console;
        /// <br />
        /// ������� ����� � �������;
        /// </summary>
        /// <exception cref="ArgumentNullException">Whether the pointer to the order is actually null;<br />��������, �� ��������� �� Order �� null;</exception>
        public void Print()
        {
            if (OrderReference == null) throw new ArgumentNullException("The order you passed was null.");
            else
            {
                int nDaysCounter = 1;
                foreach (var days in OrderReference.FoodList)
                {
                    AnsiConsole.WriteLine();
                    AnsiConsole.Write(new Markup("\t[underline]Day " + nDaysCounter + "[/]\n\n"));
                    foreach (var meals in days)
                    {
                        foreach (var courses in meals)
                        {
                            AnsiConsole.Write(new Markup(
                                "[yellow]" + courses.Name + "[/]" + "  " +
                                "[red]" + courses.Calories + " cal[/]" + "   " +
                                "[green]" + "$" + courses.Price + "[/]" + "\n"));
                        }
                        AnsiConsole.WriteLine();
                    }
                    nDaysCounter++;
                    AnsiConsole.WriteLine();
                }

                AnsiConsole.WriteLine();
                AnsiConsole.WriteLine();


                // Print total;
                AnsiConsole.Write(new Markup($"\t[underline]Total:[/]\t[green]$" + OrderReference.OverallPrice.ToString("n2") +
                    "[/]\t [red]" + OrderReference.OverallCalories + " cal[/]." + "\n\n\tCurrent discount is " + OrderReference.DiscountValueInPercent + "%."));

                AnsiConsole.WriteLine();
                AnsiConsole.WriteLine();
            }
        }


        #endregion API


    }
}