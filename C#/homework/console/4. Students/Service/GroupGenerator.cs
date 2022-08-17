using System;

using Spectre.Console;


namespace Homework.NET
{
    /// <summary>
    /// A service for assembling random groups of students;
    /// <br />
    /// ������ ��� ���������� ����� �������� ���������� �������;
    /// </summary>
    public class GroupGenerator
    {


        #region LOGIC


        /// <summary>
        /// Create new group with random data;
        /// <br />
        /// ������� ����� ������ �� ���������� �������;
        /// </summary>
        /// <returns> Random group;<br />��������� ������;</returns>
        public Group GenerateNewGroup()
        {
            int nRandom = new Random().Next() % 5;

            string sName = "Group ";

            char cLetter = 'A';

            switch (nRandom)
            {
                case 0:
                    cLetter = 'A';
                    break;
                case 1:
                    cLetter = 'B';
                    break;
                case 2:
                    cLetter = 'C';
                    break;
                case 3:
                    cLetter = 'D';
                    break;
                case 4:
                    cLetter = 'E';
                    break;
            }

            sName += cLetter;

            Group result = new Group(sName);

            AddSomeStudents(ref result);

            AddSomeSubjects(ref result);

            AddSomeGrades(ref result);

            return result;
        }


        /// <summary>
        /// Add students to the group;
        /// <br />
        /// �������� �������� � ������;
        /// </summary>
        /// <param name="group"> A group to be changed;<br /> ������, ������� ����� ���������;</param>
        private void AddSomeStudents(ref Group group)
        {
            int nRandom = 2 + (new Random().Next() % 3);

            Student[] students = new Student[nRandom];

            string sLastName = "Student";

            List<string> sFirstNames = new List<string>();

            sFirstNames.Add("First");
            sFirstNames.Add("Second");
            sFirstNames.Add("Third");
            sFirstNames.Add("Fourth");

            for (int i = 0, nSize = nRandom; i < nSize; i++)
            {
                students[i] = new Student(sFirstNames[i], sLastName);
                group.AddStudent(students[i]);
            }
        }


        /// <summary>
        /// Add subjects to the group;
        /// <br />
        /// �������� ��������� � ������;
        /// </summary>
        /// <param name="group"> A group to be changed;<br /> ������, ������� ����� ���������;</param>
        private void AddSomeSubjects(ref Group group)
        {
            Subject CurrentSubject;

            List<string> lSubjectNames = new List<string>();

            int nRandom = 3 + (new Random().Next() % 3);

            lSubjectNames.Add("Math");
            lSubjectNames.Add("English");
            lSubjectNames.Add("Computer Science");
            lSubjectNames.Add("Physics");
            lSubjectNames.Add("Chemistry");
            lSubjectNames.Add("Carpentry");

            for (int i = 0, nSize = nRandom; i < nSize; i++)
            {
                CurrentSubject = new Subject(lSubjectNames[i]);
                group.AddSubject(CurrentSubject);
            }
        }


        /// <summary>
        /// Add grades to group's students;
        /// <br />
        /// �������� ������ ��������;
        /// </summary>
        /// <param name="group"> A group to be changed;<br /> ������, ������� ����� ���������;</param>
        private void AddSomeGrades(ref Group group)
        {
            Grade CurrentGrade;

            int nRandomGradeValue;

            int nRandomGradesAmount;

            foreach (Subject subject in group.Subjects)
            {
                foreach (Student student in group.Students)
                {
                    nRandomGradesAmount = 2 + (new Random().Next() % 3);

                    for (int i = 0, nSize = nRandomGradesAmount; i < nSize; i++)
                    {
                        nRandomGradeValue = new Random().Next() % (Grade.MAX_VALUE + 1);

                        CurrentGrade = new Grade(subject, nRandomGradeValue);

                        student.AddGrade(CurrentGrade);
                    }
                }
            }
        }


        #endregion LOGIC



        #region CONSTRUCTION

        /// <summary>
        /// The instance of a class;
        /// <br />
        /// ��������� ������;
        /// </summary>
        private static GroupGenerator instance;


        /// <summary>
        /// Default constructor;
        /// <br />
        /// ����������� �� ���������;
        /// </summary>
        private GroupGenerator()
        {

        }


        /// <summary>
        /// Get instance of a class;
        /// <br />
        /// �������� ���������� ������;
        /// </summary>
        /// <returns>
        /// A pointer to the instance;
        /// <br />
        /// ��������� �� ���������;
        /// </returns>
        public static GroupGenerator GetInstance()
        {
            if (instance == null)
            {
                instance = new GroupGenerator();
            }
            return instance;
        }


        #endregion CONSTRUCTION


    }
}