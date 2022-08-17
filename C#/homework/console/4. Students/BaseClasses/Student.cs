using System;


namespace Homework.NET
{
    /// <summary>
    /// 'Student' class;
    /// <br />
    /// ����� '�������';
    /// </summary>
    public class Student
    {


        #region FIELDS


        /// <summary>
        /// First Name;
        /// <br />
        /// ���;
        /// </summary>
        private string _firstName;


        /// <summary>
        /// Last Name;
        /// <br />
        /// �������;
        /// </summary>
        private string _lastName;


        /// <summary>
        /// A list of grades;
        /// <br />
        /// ������ ������;
        /// </summary>
        private List<Grade>? _gradesList;


        /// <summary>
        /// A pointer to the Group;
        /// <br />
        /// ��������� �� ������;
        /// </summary>
        private Group? _group = null;


        #endregion FIELDS



        #region PROPERTIES


        /// <summary>
        /// Property for '_firstName' field;
        /// <br />
        /// �������� ���� '_firstName';
        /// </summary>
        public string FirstName
        {
            get { return _firstName; }
            set { _firstName = value; }
        }


        /// <summary>
        /// Property for '_lastName' field;
        /// <br />
        /// �������� ���� '_lastName';
        /// </summary>
        public string LastName
        {
            get { return _lastName; }
            set { _lastName = value; }
        }


        /// <summary>
        /// Property for '_gradesList' field;
        /// <br />
        /// �������� ���� '_gradesList';
        /// </summary>
        public List<Grade> GradesList
        {
            get { return _gradesList; }
        }


        /// <summary>
        /// Property for '_group' field;
        /// <br />
        /// �������� ���� '_group';
        /// </summary>
        public Group? Group
        {
            set { _group = value; }
            get { return _group; }
        }


        #endregion PROPERTIES



        #region CONSTRUCTION


        /// <summary>
        /// A fullname constructor;
        /// <br />
        /// ���������� "�������-���";
        /// </summary>
        /// <param name="firstName">���</param>
        /// <param name="lastName">�������</param>
        public Student(string firstName, string lastName)
        {
            FirstName = firstName;
            LastName = lastName;
            _gradesList = new List<Grade>();
        }


        /// <summary>
        /// A full constructor;
        /// <br />
        /// ������ �����������;
        /// </summary>
        /// <param name="firstName">���</param>
        /// <param name="lastName">�������</param>
        /// <param name="group">��������� �� ������</param>
        public Student(string firstName, string lastName, Group group) : this(firstName, lastName)
        {
            Group = group;
        }


        #endregion CONSTRUCTION



        #region LOGIC


        /// <summary>
        /// Get average Grade for all subjects;
        /// <br />
        /// �������� ������� ���������� ���� ������ �� ���� ���������;
        /// </summary>
        /// <returns>������� ���������� ���� ������</returns>
        public int? GetAverageGrade()
        {
            int? nAvg = 0;

            if (_gradesList != null)
            {

                foreach (Grade grade in _gradesList)
                {
                    nAvg += grade.Value;
                }

                nAvg /= _gradesList.Count;
            }

            return nAvg;
        }


        /// <summary>
        /// Get average grades for all subjects;
        /// <br />
        /// �������� ������� ������ �� ������� ��������;
        /// </summary>
        /// <returns>A list of grades; <br />������ ������; </returns>
        /// <exception cref="NullReferenceException"></exception>
        public List<int> GetAverageGradesForAllSubjects()
        {
            // Create a list;
            List<int> Result = new List<int>();

            // Check for 'null';
            if (Group == null || Group.Subjects == null || _gradesList == null) throw new NullReferenceException("This student hasn't been assigned to a group or the group has no subjects.");

            // A variable for AVG value;
            int tempAVG;

            // Iterate through each subject to get the AVG value;
            for (int i = 0, sbj_size = Group.Subjects.Count, grd_counter; i < sbj_size; ++i)
            {
                tempAVG = 0;
                grd_counter = 0;
                for (int j = 0, grd_count = _gradesList.Count; j < grd_count; ++j)
                {
                    if (_gradesList[j].Subject == Group.Subjects[i])
                    {
                        tempAVG += (int)_gradesList[j].Value;
                        grd_counter++;
                    }
                }
                tempAVG /= grd_counter;
                Result.Add(tempAVG);
            }

            // Return the list;
            return Result;

        }


        /// <summary>
        /// Add a grade;
        /// <br />
        /// �������� ������;
        /// </summary>
        /// <param name="grade"></param>
        public void AddGrade(Grade grade)
        {
            if (grade != null)
            {
                // If list hasn't been created yet - create;
                if (_gradesList == null) _gradesList = new List<Grade>();

                // Assign this student to the grade;
                grade.Student = this;

                // Actually add a grade;
                _gradesList.Add(grade);

                // Sort the list to have all grades ready to be printed out;
                _gradesList.Sort(
                    delegate(Grade grd1, Grade grd2)
                    {
                        return string.Compare(grd1.Subject.Name, grd2.Subject.Name);
                    }
                );
            }
        }


        #endregion LOGIC

    }
}