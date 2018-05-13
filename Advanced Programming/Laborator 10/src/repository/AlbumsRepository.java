package repository;

import entity.AlbumsEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author Victor Manoliu on 11-May-18
 */
@Repository
public interface AlbumsRepository  {

    @Query(value = "select t from Albums t where t.releaseYear = :releaseYear")
    AlbumsEntity findAlbumByReleaseYear(Long releaseYear);

    @Query(value = "select count(t) from Albums t")
    long count();

    @Query(value = "delete from Albums t")
    void deleteAll();

    @Query(value = "select t from Albums t")
    List<AlbumsEntity> findAll();

}
