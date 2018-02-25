package compulsory;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Victor Manoliu on 25-Feb-18
 */

public class Student {

    private String studentName;
    private String studentMail;
    private List<Project> preferences;

    /**
     * Builds a new instance of a student
     *
     * @param name Name of this student
     * @param mail Mail of this student
     */

    public Student(String name, String mail) {
        studentName = name;
        studentMail = mail;
        preferences = new ArrayList<Project>();
    }

    /**
     * Setter for the mail of a student
     *
     * @param studentMail Mail of a student
     */

    public void setStudentMail(String studentMail) {
        this.studentMail = studentMail;
    }

    /**
     * Setter for the mail of a student
     *
     * @param studentName Name of a student
     */

    public void setStudentName(String studentName) {
        this.studentName = studentName;
    }

    /**
     * Getter for the mail of a student
     *
     * @return The mail of a student
     */

    public String getStudentMail() {
        return studentMail;
    }

    /**
     * Getter for the name of the student
     *
     * @return The name of a student
     */

    public String getStudentName() {
        return studentName;
    }

    /**
     * Setter method for the teacher preferences regarding projects
     *
     * @param preferencesArguments A variable argument lists of projects
     */

    public void setPreferences(Project... preferencesArguments) {
        for (Project i : preferencesArguments) {
            preferences.add(i);
        }
    }

    /**
     * Getter for preferences regarding the projects
     *
     * @return A list of prefered projects by a student
     */

    public List<Project> getPreferences() {
        return preferences;
    }

    /**
     * Gets the string representation of this object
     *
     * @return The string representation of this object
     */

    public String toString() {
        return "S(" + studentName + " " + studentMail + ")";
    }
}
