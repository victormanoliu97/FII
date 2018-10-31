using System.ComponentModel.DataAnnotations;

namespace Laborator_05.PoiData
{
    public class Poi
    {
        public Poi(int poiId, string name, string description, int cityId)
        {
            PoiId = poiId;
            Name = name;
            Description = description;
            CityId = cityId;
        }

        public int PoiId { get; private set; }

        [Required(ErrorMessage = "You need to provide the POI name")]
        [MinLength(50)]
        [MaxLength(100)]
        public string Name { get; private set; }

        [Required(ErrorMessage = "You need to provide the POI description")]
        [MaxLength(150)]
        public string Description { get; private set; }

        public int CityId { get; private set; }
        public CityData.City City { get; private set; }
    }
}
