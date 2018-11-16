using System.Collections.Generic;

namespace DataLayer.CityData
{
    public class City
    {
        public City()
        {

        }

        public City(int cityId, string name, string description, double latitude, double longitude)
        {
            CityId = cityId;
            Name = name;
            Description = description;
            Latitude = latitude;
            Longitude = longitude;
        }

        public int CityId { get; set; }

        public string Name { get; set; }

        public string Description { get; set; }

        public ICollection<PoiData.Poi> Pois { get; set; }

        public double Latitude { get; set; }
        public double Longitude { get; set; }
    }
}
