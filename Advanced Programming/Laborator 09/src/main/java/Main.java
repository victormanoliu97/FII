import dao.AlbumDAO;
import dao.ArtistDAO;
import db.Database;
import generator.RandomDataGenerator;
import generator.ReportGenerator;

import java.sql.SQLException;

/**
 * @author Victor Manoliu on 28-Apr-18
 */
public class Main {

    public static void main(String[] args)
    {
        ReportGenerator reportGenerator = new ReportGenerator();
        reportGenerator.generateHTMLRaport();
        try {
            ArtistDAO artists = new ArtistDAO();
            AlbumDAO albums = new AlbumDAO();

            artists.create("Radiohead", "United Kingdom");
            artists.create("Phoenix", "Romania");
            Database.commit();

            int phoenixId = artists.findByName("Phoenix");
            albums.create(phoenixId, "Mugur de fluier", 1974);

            int radioheadId = artists.findByName("Radiohead");

            albums.create(radioheadId,"OK COMPUTER", 1977);
            albums.create(radioheadId, "Kid A", 2000);
            albums.create(radioheadId, "In Rainbows", 2007);

            albums.list(radioheadId);

            Database.commit();

            RandomDataGenerator randomDataGenerator = new RandomDataGenerator();
            randomDataGenerator.generateArtistData();
            randomDataGenerator.generateAlbumData("Radiohead");

            Database.commit();


            Database.closeConnection();
        } catch (SQLException e) {
            System.err.println(e);
            Database.rollback();
        }
    }
}
