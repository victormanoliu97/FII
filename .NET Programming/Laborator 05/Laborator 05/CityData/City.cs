using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace Laborator_05.CityData
{
    public class City
    {
        public City(int cityId, string name, string description, double latitude, double longitude)
        {
            CityId = cityId;
            Name = name;
            Description = description;
            Latitude = latitude;
            Longitude = longitude;
        }

        public int CityId { get; private set; }

        [Required(ErrorMessage = "You need to provide the city name")]
        [MinLength(50)]
        [MaxLength(100)]
        public string Name { get; private set; }

        [Required(ErrorMessage = "You need to provide the city description")]
        [MaxLength(150)]
        public string Description { get; private set; }


        public double Latitude { get; private set; }
        public double Longitude { get; private set; }

        public ICollection<PoiData.Poi> Pois { get; private set; }


        public override string ToString()
        {
            return CityId + " " + Name + " " + Description + " " + Latitude + " " + Longitude;
        }
    }
}
