package compulsory;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Victor Manoliu on 25-Feb-18
 */

public class Problem {

    private List<Student> students;
    private List<Teacher> teachers;

    /**
     * Builds a new instance of the problem
     */

    public Problem() {
        students = new ArrayList<Student>();
        teachers = new ArrayList<Teacher>();
    }

    /**
     * Setter method of the students for the problem
     *
     * @param studentList A list of students
     */

    public void setStudents(Student... studentList) {
        for (Student i : studentList) {
            students.add(i);
        }
    }

    /**
     * Getter method of the students
     *
     * @return A list of students
     */

    public List<Student> getStudents() {
        return students;
    }

    /**
     * Setter method of the teachers for the problem
     *
     * @param teacherList A list of teachers
     */

    public void setTeachers(Teacher... teacherList) {
        for (Teacher i : teacherList) {
            teachers.add(i);
        }
    }

    /**
     * Getter method of the teachers
     *
     * @return A list of teachers
     */

    public List<Teacher> getTeachers() {
        return teachers;
    }


    /**
     * String representation of this object
     *
     * @return String representation of this object
     */

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();

        for (Student i : students) {
            stringBuilder.append(i.toString() + ":");
        }

        stringBuilder.append("::");

        for (Teacher i : teachers) {
            stringBuilder.append(i.toString() + ":");
        }

        return stringBuilder.toString();
    }


}
