package db;

import oracle.jdbc.pool.OracleDataSource;

import java.sql.Connection;
import java.sql.SQLException;

/**
 * @author Victor Manoliu on 28-Apr-18
 */
public class Database {

    private static final String URL = "jdbc:oracle:thin:@127.0.0.1:1521:XE";
    private static final String USER = "student";
    private static final String PASSWORD = "STUDENT";
    private static Connection connection = null;

    private Database() {
    }

    public static Connection getConnection() {
        if (connection == null) {
            createConnection();
        }
        return connection;
    }

    public static void createConnection() {
        try {
            Class.forName("oracle.jdbc.OracleDriver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        OracleDataSource dataSource = null;
        try {
            dataSource = new OracleDataSource();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        dataSource.setURL(URL);
        try {
            connection = dataSource.getConnection(USER, PASSWORD);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void closeConnection() {
        try {
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void commit() {
        try {
            connection.setAutoCommit(false);
            connection.commit();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void rollback() {
        try {
            connection.setAutoCommit(false);
            connection.rollback();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }


}
