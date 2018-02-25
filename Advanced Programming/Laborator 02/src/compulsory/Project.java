package compulsory;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Victor Manoliu on 25-Feb-18
 */

public class Project {

    private String projectName;
    private int projectCapacity;
    private List<Student> preferences;

    /**
     * Builds a new instance of a project
     *
     * @param projectName     The name of the project
     * @param projectCapacity The available capacity of a project
     */

    public Project(String projectName, int projectCapacity) {
        this.projectName = projectName;
        this.projectCapacity = projectCapacity;
        preferences = new ArrayList<Student>();
    }

    /**
     * Getter method for name
     *
     * @return The name of a project
     */

    public String getProjectName() {
        return projectName;
    }

    /**
     * Getter method for capacity
     *
     * @return The capacity of a project
     */

    public int getProjectCapacity() {
        return projectCapacity;
    }

    /**
     * Setter method for the capacity of a project
     *
     * @param projectCapacity The capacity of a project
     */

    public void setProjectCapacity(int projectCapacity) {
        this.projectCapacity = projectCapacity;
    }

    /**
     * Setter method for the name of a project
     *
     * @param projectName The name of a project
     */

    public void setProjectName(String projectName) {
        this.projectName = projectName;
    }

    public String toString() {
        return "P(" + projectName + " " + String.valueOf(projectCapacity) + ")";
    }

}
