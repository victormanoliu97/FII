namespace DataLayer.PoiData
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

        public int PoiId { get; set; }

        public string Name { get; set; }

        public string Description { get; set; }

        public int CityId { get; set; }
        public CityData.City City { get; private set; }
    }
}
