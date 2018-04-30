package dao;

import db.Database;
import oracle.jdbc.proxy.annotation.Pre;

import java.sql.*;

/**
 * @author Victor Manoliu on 28-Apr-18
 */
public class ArtistDAO {

    public void create(String name, String country) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("insert into artists (name, country) values (?, ?)")) {
            pstmt.setString(1, name);
            pstmt.setString(2, country);
            pstmt.executeUpdate();
        }
    }

    public Integer findByName(String name) throws SQLException {
        String sql = "select id from artists where name=?";
        Connection con = Database.getConnection();
        try (PreparedStatement stmt = con.prepareStatement(sql)) {
            stmt.setString(1, name);
            try (ResultSet rs = stmt.executeQuery()) {
                return rs.next() ? rs.getInt(1) : null;
            }
        }
    }
}
