package app;

import controller.AlbumController;
import controller.ArtistController;
import entity.AlbumsEntity;
import entity.ArtistsEntity;
import repository.AlbumsRepository;
import repository.ArtistRepository;

import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.transaction.Transactional;
import java.util.Scanner;

/**
 * @author Victor Manoliu on 09-May-18
 */
public class AlbumManager {

    static final EntityManagerFactory emf = Persistence.createEntityManagerFactory("MusicAlbumsPU");
    public ArtistController artistController = new ArtistController(emf);
    public AlbumController albumController = new AlbumController(emf);
    AlbumsRepository albumsRepository;
    ArtistRepository artistRepository;

    public void run() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("Input command:");
            String command = scanner.nextLine();
            if (command.equals("exit")) break;
            String[] params = command.trim().split("\\s+");
            switch (params[0]) {
                case "create-artist":
                    createArtist(params[1]); //the artist name
                    break;
                case "create-album":
                    createAlbum(params[1], params[2]); //the album name and the artist name
                    break;
                case "list-albums":
                    listAlbums(params[1]); //the artist name
                    break;
            }
        }
    }


    private void createArtist(String artistName) {
        ArtistsEntity artistsEntity = new ArtistsEntity();
        artistsEntity.setName(artistName);
        artistsEntity.setCountry("Test");
        this.artistController.create(artistsEntity);
    }


    private void createAlbum(String albumName, String artistName) {
        AlbumsEntity albumsEntity = new AlbumsEntity();
        albumsEntity.setName(albumName);
        albumsEntity.setId(17);
        albumsEntity.setReleaseYear(Long.parseLong("2018"));
    }

    private void listAlbums(String artistName) {
        ArtistsEntity artistsEntity = artistController.findByName(artistName);
        System.out.println(albumController.listByArtist(artistsEntity));
    }

    public static void main(String args[]) {
        new AlbumManager().run();
    }


}
