package repository;

import entity.ArtistsEntity;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author Victor Manoliu on 11-May-18
 */
@Repository
public interface ArtistRepository  {

    @Query(value = "select t from Artists t where t.country = ?1", nativeQuery = true)
    List<String> findArtistByCountry(String country);

    @Query(value = "select count(t) from Artists t", nativeQuery = true)
    long count();

    @Query(value = "delete from Artits t", nativeQuery = true)
    void deleteAll();

    @Query(value = "select t from Artists t", nativeQuery = true)
    List<ArtistsEntity> findAll();
}
