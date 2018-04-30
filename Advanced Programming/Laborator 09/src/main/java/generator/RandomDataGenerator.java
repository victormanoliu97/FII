package generator;

import com.github.javafaker.Faker;
import dao.AlbumDAO;
import dao.ArtistDAO;

import java.sql.SQLException;
import java.util.Random;

/**
 * @author Victor Manoliu on 30-Apr-18
 */
public class RandomDataGenerator {

    private Faker faker = new Faker();
    private ArtistDAO artistDAO = new ArtistDAO();
    private AlbumDAO albumDAO = new AlbumDAO();

    public void generateArtistData() throws SQLException {
        String artistName = faker.artist().name();
        String artistCountry = faker.address().country();
        artistDAO.create(artistName , artistCountry);
    }

    public void generateAlbumData(String artistName) throws SQLException {
        String albumName = faker.music().chord();
        int albumReleaseYear = new Random().nextInt(2010 - 1900);

        int artistId = artistDAO.findByName(artistName);
        albumDAO.create(artistId, albumName, albumReleaseYear);
    }
}
