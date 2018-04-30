package service;

import db.Database;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * @author Victor Manoliu on 30-Apr-18
 */
public class EntityControllerImpl implements EntityController {

    @Override
    public void insertArist(String artistName, String artistCountry) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("insert into artists (name, country) values (?, ?)")) {
            pstmt.setString(1, artistName);
            pstmt.setString(2, artistCountry);
            pstmt.executeUpdate();
        }
    }

    @Override
    public void updateArtistName(Integer artistId, String artistName) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("update artists set name = ? where id = ?")) {
            pstmt.setString(1, artistName);
            pstmt.setInt(2, artistId);
            pstmt.executeUpdate();
        }
    }

    @Override
    public void updateArtistCountry(Integer artistId, String artistCountry) throws SQLException  {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("update artists set country = ? where id = ?")) {
            pstmt.setString(1, artistCountry);
            pstmt.setInt(2, artistId);
            pstmt.executeUpdate();
        }
    }

    @Override
    public void readArtists() throws SQLException {
        String sql = "select name, country from artists";
        Connection con = Database.getConnection();
        try (PreparedStatement stmt = con.prepareStatement(sql)) {
            try (ResultSet rs = stmt.executeQuery()) {
                while(rs.next())
                {
                    System.out.println(rs.getString("name") + " " + rs.getString("country"));
                }
            }
        }
    }

    @Override
    public void deleteArtist(Integer artistId) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("delete from artists where id = ?")) {
            pstmt.setInt(1, artistId);
            pstmt.executeUpdate();
        }
    }

    @Override
    public void insertAlbum(String albumName, Integer artistId, Integer releaseYear) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("insert into ALBUMS(artist_id , NAME, release_year) VALUES(?, ?, ?)")) {
            pstmt.setInt(1, artistId);
            pstmt.setString(2, albumName);
            pstmt.setInt(3, releaseYear);
            pstmt.executeUpdate();
        }
    }

    @Override
    public void updateAlbumName(Integer albumId, String albumName) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("update albums set name = ? where id = ?")) {
            pstmt.setString(1, albumName);
            pstmt.setInt(2, albumId);
            pstmt.executeUpdate();
        }
    }

    @Override
    public void updateReleaseYear(Integer albumId, Integer releaseYear) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("update albums set release_year = ? where id = ?")) {
            pstmt.setInt(1, releaseYear);
            pstmt.setInt(2, albumId);
            pstmt.executeUpdate();
        }

    }

    @Override
    public void readAlbums() throws SQLException {
        String sql = "select name, release_year from albums";
        Connection con = Database.getConnection();
        try (PreparedStatement stmt = con.prepareStatement(sql)) {
            try (ResultSet rs = stmt.executeQuery()) {
                while(rs.next())
                {
                    System.out.println(rs.getString("name") + " " + rs.getInt("release_year"));
                }
            }
        }

    }

    @Override
    public void deleteAlbum(Integer albumId) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("delete from albums where id = ?")) {
            pstmt.setInt(1, albumId);
            pstmt.executeUpdate();
        }
    }
}
