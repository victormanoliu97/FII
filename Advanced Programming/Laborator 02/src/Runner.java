import compulsory.Problem;
import compulsory.Project;
import compulsory.Student;
import compulsory.Teacher;

/**
 * @author Victor Manoliu on 25-Feb-18
 */
public class Runner {

    public static void main(String[] args) {

        //COMPULSORY PART
        Student s1 = new Student("S1", "s1@info.uaic.ro");
        Student s2 = new Student("S2", "s2@info.uaic.ro");
        Student s3 = new Student("S3", "s3@info.uaic.ro");
        Student s4 = new Student("S4", "s4@info.uaic.ro");

        Teacher t1 = new Teacher("T1", "t1@info.uaic.ro");
        Teacher t2 = new Teacher("T2", "t2@info.uaic.ro");
        Teacher t3 = new Teacher("T3", "t3@info.uaic.ro");
        Teacher t4 = new Teacher("T4", "t4@info.uaic.ro");

        Project p1 = t1.createProject("P1", 2);
        Project p2 = t2.createProject("P2", 2);

        s1.setPreferences(p1, p2);
        t1.setPreferences(s3, s2, s1, s4);

        Problem problem = new Problem();
        problem.setStudents(s1, s2, s3, s4);
        problem.setTeachers(t1, t2, t3);
        System.out.println(problem.toString());

    }
}
