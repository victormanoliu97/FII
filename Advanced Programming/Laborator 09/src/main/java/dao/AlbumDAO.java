package dao;

import db.Database;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Victor Manoliu on 28-Apr-18
 */
public class AlbumDAO {

    private List<String> albumsOfArtist = new ArrayList<>();

    public void create(Integer artistId, String albumName, Integer albumYear) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("INSERT INTO ALBUMS(artist_id , NAME, release_year) VALUES(?, ?, ?)")) {
            pstmt.setInt(1, artistId);
            pstmt.setString(2, albumName);
            pstmt.setInt(3, albumYear);
            pstmt.executeUpdate();
        }
    }

    public Integer findByName(String name) throws SQLException {
        String sql = "select id from albums where name=?";
        Connection con = Database.getConnection();
        try (PreparedStatement stmt = con.prepareStatement(sql)) {
            stmt.setString(1, name);
            try (ResultSet rs = stmt.executeQuery()) {
                return rs.next() ? rs.getInt(1) : null;
            }
        }
    }


    public void list(int artistId) throws SQLException {
        String sql = "select distinct name from albums where artist_id=?";
        Connection con = Database.getConnection();
        try (PreparedStatement stmt = con.prepareStatement(sql)) {
            stmt.setInt(1, artistId);
            try (ResultSet rs = stmt.executeQuery()) {
                while(rs.next())
                {
                    System.out.println(rs.getString("name"));
                }
            }
        }
    }


}
