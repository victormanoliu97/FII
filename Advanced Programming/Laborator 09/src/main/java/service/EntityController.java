package service;

import java.sql.SQLException;

/**
 * @author Victor Manoliu on 30-Apr-18
 */
public interface EntityController {

    void insertArist(String artistName, String artistCountry) throws SQLException;

    void updateArtistName(Integer artistId, String artistName) throws SQLException;

    void updateArtistCountry(Integer artistId, String artistCountry) throws SQLException;

    void readArtists() throws SQLException;

    void deleteArtist(Integer artistId) throws SQLException;

    void insertAlbum(String albumName, Integer artistId, Integer releaseYear) throws SQLException;

    void updateAlbumName(Integer albumId, String albumName) throws SQLException;

    void updateReleaseYear(Integer albumId, Integer releaseYear) throws SQLException;

    void readAlbums() throws SQLException;

    void deleteAlbum(Integer albumId) throws SQLException;
}
