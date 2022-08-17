using System;


namespace Homework.NET
{
    /// <summary>
    /// 'Subject' class;
    /// <br />
    /// ����� '�������';
    /// </summary>
    public class Subject
    {

        #region FIELDS


        /// <summary>
        /// The name of the subject;
        /// <br />
        /// ��� ��������;
        /// </summary>
        private string _name = "Unknown";


        #endregion FIELDS



        #region PROPERTIES


        /// <summary>
        /// Property for '_name' field;
        /// <br />
        /// �������� ���� '_name';
        /// </summary>
        public string Name
        { 
            set { _name = value; }
            get { return _name; } 
        }


        #endregion PROPERTIES



        #region CONSTRUCTION


        /// <summary>
        /// 'Name' constructor;
        /// <br />
        /// ����������� � ������;
        /// </summary>
        /// <param name="sName">��� ��������</param>
        public Subject(string sName)
        {
            Name = sName;
        }


        #endregion CONSTRUCTION



        #region OVERRIDE


        /// <summary>
        /// 'ToString()' method overrdie;
        /// <br />
        /// ���������� ������ 'ToString()';
        /// </summary>
        /// <returns>��� ��������</returns>
        public override string ToString()
        {
            return Name;
        }


        #endregion OVERRIDE


    }
}