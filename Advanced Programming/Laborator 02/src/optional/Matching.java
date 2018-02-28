package optional;

import compulsory.Problem;
import compulsory.Project;
import compulsory.Student;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author Victor Manoliu on 25-Feb-18
 */
public class Matching {

    private Problem problem;
    private Map<Project, List<Student>> matchings;

    /**
     * Builds a new instance of the Matching
     *
     * @param p The problem for which we want to apply the matching
     */


    public Matching(Problem p) {
        this.problem = p;
        matchings = new HashMap<Project, List<Student>>();
    }

    /**
     * Method to check if student is already enrolled in a project
     *
     * @param student The desired student to check for
     * @return 'true' if student is eligible ( is not enrolled in a project ) and 'false' otherwise
     */

    private boolean isEligibleStudent(Student student) {
        for (Map.Entry<Project, List<Student>> m : matchings.entrySet()) {
            for (Student s : m.getValue()) {
                if (s.equals(student)) {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * Generates the matching between students and project and stores the result in "matchings"
     */

    public void generateMatchings() {
        for (Student s : problem.getStudents()) {
            for (Project p : s.getPreferences()) {
                if (s.getPreferences().contains(p) && isEligibleStudent(s)) {
                    if (matchings.containsKey(p)) {
                        if (matchings.get(p).size() != p.getProjectCapacity()) {
                            matchings.get(p).add(s);
                        }
                    } else {
                        List<Student> students = new ArrayList<Student>();
                        students.add(s);
                        matchings.put(p, students);
                    }
                }
            }
        }
    }

    /**
     * Prints the generated matching between students and projects
     */

    public void printMatching() {
        for (Map.Entry<Project, List<Student>> matching : matchings.entrySet()) {
            System.out.print(matching.getKey() + ": ");
            for (Student s : matching.getValue()) {
                System.out.print("\t" + s);
            }
            System.out.println();
        }
    }

}
