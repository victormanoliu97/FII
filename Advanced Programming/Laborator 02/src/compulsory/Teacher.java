package compulsory;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Victor Manoliu on 25-Feb-18
 */

public class Teacher {

    private String teacherName;
    private String teacherMail;
    private List<Project> projectList;
    private List<Student> preferences;

    /**
     * Builds a new instance of a teacher
     *
     * @param teacherName the name of a teacher
     * @param teacherMail the mail of a teacher
     */

    public Teacher(String teacherName, String teacherMail) {
        this.teacherName = teacherName;
        this.teacherMail = teacherMail;
        preferences = new ArrayList<Student>();
    }

    /**
     * Getter method for the teacher name
     *
     * @return the teacher name
     */

    public String getTeacherName() {
        return teacherName;
    }

    /**
     * Getter method for the teacher mail
     *
     * @return the teacher mail
     */

    public String getTeacherMail() {
        return teacherMail;
    }

    /**
     * Setter method for the teacher name
     *
     * @param teacherName the teacher name
     */

    public void setTeacherName(String teacherName) {
        this.teacherName = teacherName;
    }

    /**
     * Setter method for the teacher mail
     *
     * @param teacherMail the teacher mail
     */

    public void setTeacherMail(String teacherMail) {
        this.teacherMail = teacherMail;
    }

    /**
     * Builds a new instance of a project
     *
     * @param projectName     the name of the project
     * @param projectCapacity the available capacity of the project
     * @return the newly created instance of the project
     */

    public Project createProject(String projectName, int projectCapacity) {
        Project test = new Project(projectName, projectCapacity);

        test.setProjectName(projectName);
        test.setProjectCapacity(projectCapacity);

        return test;
    }

    /**
     * Setter method for the teacher preferences regarding students
     *
     * @param preferencesArguments A variable argument lists of students
     */

    public void setPreferences(Student... preferencesArguments) {
        for (Student i : preferencesArguments) {
            preferences.add(i);
        }
    }

    /**
     * Getter method for a teacher preferences reharding students
     *
     * @return A list of prefered students by a teacher
     */

    public List<Student> getPreferences() {
        return preferences;
    }

    /**
     * Gets the string representation of this object
     *
     * @return The string representation of this object
     */

    public String toString() {
        return "T(" + teacherName + " " + teacherMail + ")";
    }
}
