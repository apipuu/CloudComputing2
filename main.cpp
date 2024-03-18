#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double toRadians(double angle) {
    return angle * PI / 180.0;
}

double toDegrees(double radian) {
    return radian * 180.0 / PI;
}

int main() {
    double RHO = 8.859375;
    double THETA_deg = 134.807739257812;
    int TN = 747;
    double X = 6.28125;
    double Y = -6.2421875;
    double Groundspeed_NMps = 0.00799560546875;

    // Konversi polar coordinates (RHO, THETA) to Cartesian (X, Y)
    double THETA_rad = toRadians(THETA_deg);
    X = RHO * cos(THETA_rad);
    Y = RHO * sin(THETA_rad);

    // Asumsi lokasi radar 
    double RadarLatitude_deg = 108.70809561263313;
    double RadarLongitude_deg = -5.38228258415249;

    // Convert Cartesian coordinates (X, Y) to geographical coordinates (longitude, latitude)
    double X_NM = X / 60.0;
    double Y_NM = Y / 60.0;
    double Longitude = RadarLongitude_deg + X_NM / cos(toRadians(RadarLatitude_deg));
    double Latitude = RadarLatitude_deg + Y_NM;

    // Convert speed from NM/s to knots
    double Groundspeed_knots = Groundspeed_NMps * 3600.0 / 1852.0;

    // Convert Cartesian coordinates (X, Y) to geographical coordinates (longitude, latitude)
    double dlon = toRadians(Longitude - RadarLongitude_deg);
    double dlat = toRadians(Latitude - RadarLatitude_deg);
    double a = sin(dlat/2) * sin(dlat/2) + cos(toRadians(RadarLatitude_deg)) * cos(toRadians(Latitude)) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance_km = 6371 * c; // Radius Bumi dalam kilometer

    // Convert Cartesian coordinates (X, Y) to geographical coordinates (longitude, latitude)
    double y = sin(dlon) * cos(Latitude);
    double x = cos(toRadians(RadarLatitude_deg)) * sin(Latitude) - sin(toRadians(RadarLatitude_deg)) * cos(Latitude) * cos(dlon);
    double bearing = toDegrees(atan2(y, x));

    // Output results
    printf("=============================================\n");
    printf("RHO : %f\n", RHO);
    printf("Theta : %f\n", THETA_deg);
    printf("=============================================\n\n");
    printf("HASIL KONVERSI KE KOORDINAT KARTESIAN\n\n");
    printf("X : %f\n", X);
    printf("Y : %f\n\n", Y);
	printf("=============================================\n");
	printf("Longitude Radar : %f\n", RadarLongitude_deg);
    printf("Latitude Radar : %f\n", RadarLatitude_deg);
    printf("=============================================\n");
    printf("HASIL KONVERSI DARI KARTESIAN KE GEOGRAPHIC\n\n");
    printf("Longitude Target: %f\n", Longitude);
    printf("Latitude Target: %f\n", Latitude);
    printf("=============================================\n");
    printf("Jarak Ke target (km): %f\n", distance_km);
    printf("Bearing to target (deg): %f\n", bearing);


    return 0;
}

