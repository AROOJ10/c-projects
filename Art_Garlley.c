#include <stdio.h>
#include <string.h>

// Structure Definitions
struct Artist {
    int id;
    char name[50];
    char nationality[30];
};

struct Artwork {
    int id;
    char title[50];
    int year;
    int artistId;  // Artist ID to link to Artist
    int isSold;    // 1 if sold, 0 otherwise
};

struct Exhibition {
    int id;
    char name[50];
    char startDate[20];
    char endDate[20];
    int artworkIds[10];  // Array of Artwork IDs
    int artworkCount;
    int soldArtworks;
};

struct Visitor {
    int id;
    char name[50];
    char visitDate[20];
    int exhibitionId;  // Exhibition ID to link to Exhibition
};

// Global Variables
struct Artist artists[10];
struct Artwork artworks[30];
struct Exhibition exhibitions[10];
struct Visitor visitors[50];
int artistCount = 0;
int artworkCount = 0;
int exhibitionCount = 0;
int visitorCount = 0;

// Function Prototypes
void manageDataMenu();
void artistMenu();
void addArtist();
void displayArtists();
void updateArtist();
void deleteArtist();
void artworkMenu();
void addArtwork();
void displayArtworks();
void updateArtwork();
void deleteArtwork();
void exhibitionMenu();
void addExhibition();
void displayExhibitions();
void updateExhibition();
void deleteExhibition();
void visitorMenu();
void addVisitor();
void displayVisitors();
void updateVisitor();
void deleteVisitor();
void searchMenu();
void searchByArtistName();
void searchByExhibitionDate();
void generateReport();
void loadData();
void saveData(); 
int main() {
     loadData();
    int choice;
    do {
        printf("\n**************************************\n");
        printf("\nArt Gallery Management System\n");
        printf("\n**************************************\n");

        printf("1. Manage Data\n");
        printf("2. Search\n");
        printf("3. Reports\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manageDataMenu();
                break;
            case 2:
                searchMenu();
                break;
            case 3:
                generateReport();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
saveData();  
    return 0;
}

void manageDataMenu() {
    int choice;
    do {
        printf("\n**************************************\n");
        printf("\nManage Data Menu\n");
        printf("\n**************************************\n");
        printf("1. Manage Artists\n");
        printf("2. Manage Artworks\n");
        printf("3. Manage Exhibitions\n");
        printf("4. Manage Visitors\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                artistMenu();
                break;
            case 2:
                artworkMenu();
                break;
            case 3:
                exhibitionMenu();
                break;
            case 4:
                visitorMenu();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

void artistMenu() {
    int choice;
    do {
        printf("\n**************************************\n");
        printf("\nArtist Menu\n");
        printf("\n**************************************\n");
        printf("1. Add Artist\n");
        printf("2. Display Artists\n");
        printf("3. Update Artist\n");
        printf("4. Delete Artist\n");
        printf("0. Back to Manage Data Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addArtist();
                break;
            case 2:
                displayArtists();
                break;
            case 3:
                updateArtist();
                break;
            case 4:
                deleteArtist();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

void addArtist() {

    if (artistCount < 10) {
        printf("Enter Artist ID: ");
        scanf("%d", &artists[artistCount].id);
        printf("Enter Artist Name: ");
        scanf("%s", artists[artistCount].name);
        printf("Enter Artist Nationality: ");
        scanf("%s", artists[artistCount].nationality);
        artistCount++;
    } else {
        printf("Maximum artists reached!\n");
    }
}

void displayArtists() {
    printf("\nArtists:\n");
    for (int i = 0; i < artistCount; i++) {
        printf("ID: %d, Name: %s, Nationality: %s\n", artists[i].id, artists[i].name, artists[i].nationality);
    }
}

void updateArtist() {
    int id, found = 0;
    printf("Enter Artist ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < artistCount; i++) {
        if (artists[i].id == id) {
            printf("Enter new Artist Name: ");
            scanf("%s", artists[i].name);
            printf("Enter new Artist Nationality: ");
            scanf("%s", artists[i].nationality);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Artist with ID %d not found.\n", id);
    }
}

void deleteArtist() {
    int id, found = 0;
    printf("Enter Artist ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < artistCount; i++) {
        if (artists[i].id == id) {
            for (int j = i; j < artistCount - 1; j++) {
                artists[j] = artists[j + 1];
            }
            artistCount--;
            printf("Artist with ID %d deleted.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Artist with ID %d not found.\n", id);
    }
}

void artworkMenu() {
    int choice;
    do {
        printf("\n**************************************\n");
        printf("\nArtwork Menu\n");
        printf("\n**************************************\n");
        printf("1. Add Artwork\n");
        printf("2. Display Artworks\n");
        printf("3. Update Artwork\n");
        printf("4. Delete Artwork\n");
        printf("0. Back to Manage Data Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addArtwork();
                break;
            case 2:
                displayArtworks();
                break;
            case 3:
                updateArtwork();
                break;
            case 4:
                deleteArtwork();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

void addArtwork() {
    if (artworkCount < 30) {
        printf("Enter Artwork ID: ");
        scanf("%d", &artworks[artworkCount].id);
        printf("Enter Artwork Title: ");
        scanf("%s", artworks[artworkCount].title);
        printf("Enter Artwork Year: ");
        scanf("%d", &artworks[artworkCount].year);
        printf("Enter Artist ID: ");
        scanf("%d", &artworks[artworkCount].artistId);
        artworks[artworkCount].isSold = 0; // Initialize as not sold
        artworkCount++;
    } else {
        printf("Maximum artworks reached!\n");
    }
}

void displayArtworks() {
    printf("\nArtworks:\n");
    for (int i = 0; i < artworkCount; i++) {
        printf("ID: %d, Title: %s, Year: %d, Artist ID: %d, Sold: %s\n", artworks[i].id, artworks[i].title, artworks[i].year, artworks[i].artistId, artworks[i].isSold ? "Yes" : "No");
    }
}

void updateArtwork() {
    int id, found = 0;
    printf("Enter Artwork ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < artworkCount; i++) {
        if (artworks[i].id == id) {
            printf("Enter new Artwork Title: ");
            scanf("%s", artworks[i].title);
            printf("Enter new Artwork Year: ");
            scanf("%d", &artworks[i].year);
            printf("Enter new Artist ID: ");
            scanf("%d", &artworks[i].artistId);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Artwork with ID %d not found.\n", id);
    }
}

void deleteArtwork() {
    int id, found = 0;
    printf("Enter Artwork ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < artworkCount; i++) {
        if (artworks[i].id == id) {
            for (int j = i; j < artworkCount - 1; j++) {
                artworks[j] = artworks[j + 1];
            }
            artworkCount--;
            printf("Artwork with ID %d deleted.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Artwork with ID %d not found.\n", id);
    }
}

void exhibitionMenu() {
    int choice;
    do {
        printf("\n**************************************\n");
        printf("\nExhibition Menu\n");
        printf("\n**************************************\n");
        printf("1. Add Exhibition\n");
        printf("2. Display Exhibitions\n");
        printf("3. Update Exhibition\n");
        printf("4. Delete Exhibition\n");
        printf("0. Back to Manage Data Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExhibition();
                break;
            case 2:
                displayExhibitions();
                break;
            case 3:
                updateExhibition();
                break;
            case 4:
                deleteExhibition();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

void addExhibition() {
    if (exhibitionCount < 10) {
        printf("Enter Exhibition ID: ");
        scanf("%d", &exhibitions[exhibitionCount].id);
        printf("Enter Exhibition Name: ");
        scanf("%s", exhibitions[exhibitionCount].name);
        printf("Enter Start Date (dd/mm/yyyy): ");
        scanf("%s", exhibitions[exhibitionCount].startDate);
        printf("Enter End Date (dd/mm/yyyy): ");
        scanf("%s", exhibitions[exhibitionCount].endDate);
        exhibitions[exhibitionCount].artworkCount = 0;
        exhibitionCount++;
    } else {
        printf("Maximum exhibitions reached!\n");
    }
}

void displayExhibitions() {
    printf("\nExhibitions:\n");
    for (int i = 0; i < exhibitionCount; i++) {
        printf("ID: %d, Name: %s, Start Date: %s, End Date: %s\n", exhibitions[i].id, exhibitions[i].name, exhibitions[i].startDate, exhibitions[i].endDate);
        printf("Artworks in this Exhibition:\n");
        for (int j = 0; j < exhibitions[i].artworkCount; j++) {
            int artworkId = exhibitions[i].artworkIds[j];
            for (int k = 0; k < artworkCount; k++) {
                if (artworks[k].id == artworkId) {
                    printf("  ID: %d, Title: %s, Year: %d, Artist ID: %d, Sold: %s\n", artworks[k].id, artworks[k].title, artworks[k].year, artworks[k].artistId, artworks[k].isSold ? "Yes" : "No");
                }
            }
        }
    }
}

void updateExhibition() {
    int id, found = 0;
    printf("Enter Exhibition ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < exhibitionCount; i++) {
        if (exhibitions[i].id == id) {
            printf("Enter new Exhibition Name: ");
            scanf("%s", exhibitions[i].name);
            printf("Enter new Start Date (dd/mm/yyyy): ");
            scanf("%s", exhibitions[i].startDate);
            printf("Enter new End Date (dd/mm/yyyy): ");
            scanf("%s", exhibitions[i].endDate);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Exhibition with ID %d not found.\n", id);
    }
}

void deleteExhibition() {
    int id, found = 0;
    printf("Enter Exhibition ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < exhibitionCount; i++) {
        if (exhibitions[i].id == id) {
            for (int j = i; j < exhibitionCount - 1; j++) {
                exhibitions[j] = exhibitions[j + 1];
            }
            exhibitionCount--;
            printf("Exhibition with ID %d deleted.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Exhibition with ID %d not found.\n", id);
    }
}

void visitorMenu() {
    int choice;
    do {
        printf("\n**************************************\n");
        printf("\nVisitor Menu\n");
        printf("\n**************************************\n");
        printf("1. Add Visitor\n");
        printf("2. Display Visitors\n");
        printf("3. Update Visitor\n");
        printf("4. Delete Visitor\n");
        printf("0. Back to Manage Data Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVisitor();
                break;
            case 2:
                displayVisitors();
                break;
            case 3:
                updateVisitor();
                break;
            case 4:
                deleteVisitor();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

void addVisitor() {
    if (visitorCount < 50) {
        printf("Enter Visitor ID: ");
        scanf("%d", &visitors[visitorCount].id);
        printf("Enter Visitor Name: ");
        scanf("%s", visitors[visitorCount].name);
        printf("Enter Visit Date (dd/mm/yyyy): ");
        scanf("%s", visitors[visitorCount].visitDate);
        printf("Enter Exhibition ID: ");
        scanf("%d", &visitors[visitorCount].exhibitionId);
        visitorCount++;
    } else {
        printf("Maximum visitors reached!\n");
    }
}

void displayVisitors() {
    printf("\nVisitors:\n");
    for (int i = 0; i < visitorCount; i++) {
        printf("ID: %d, Name: %s, Visit Date: %s, Exhibition ID: %d\n", visitors[i].id, visitors[i].name, visitors[i].visitDate, visitors[i].exhibitionId);
    }
}

void updateVisitor() {
    int id, found = 0;
    printf("Enter Visitor ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < visitorCount; i++) {
        if (visitors[i].id == id) {
            printf("Enter new Visitor Name: ");
            scanf("%s", visitors[i].name);
            printf("Enter new Visit Date (dd/mm/yyyy): ");
            scanf("%s", visitors[i].visitDate);
            printf("Enter new Exhibition ID: ");
            scanf("%d", &visitors[i].exhibitionId);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Visitor with ID %d not found.\n", id);
    }
}

void deleteVisitor() {
    int id, found = 0;
    printf("Enter Visitor ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < visitorCount; i++) {
        if (visitors[i].id == id) {
            for (int j = i; j < visitorCount - 1; j++) {
                visitors[j] = visitors[j + 1];
            }
            visitorCount--;
            printf("Visitor with ID %d deleted.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Visitor with ID %d not found.\n", id);
    }
}

void searchMenu() {
    int choice;
    do {
        printf("\n**************************************\n");
        printf("\nSearch Menu\n");
        printf("\n**************************************\n");
        printf("1. Search by Artist Name\n");
        printf("2. Search by Exhibition Date\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                searchByArtistName();
                break;
            case 2:
                searchByExhibitionDate();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

void searchByArtistName() {
    char name[50];
    int found = 0;
    printf("Enter Artist Name: ");
    scanf("%s", name);

    for (int i = 0; i < artistCount; i++) {
        if (strcmp(artists[i].name, name) == 0) {
            printf("\nArtist Details:\n");
            printf("ID: %d, Name: %s, Nationality: %s\n", artists[i].id, artists[i].name, artists[i].nationality);
            printf("\nArtworks by this Artist:\n");
            for (int j = 0; j < artworkCount; j++) {
                if (artworks[j].artistId == artists[i].id) {
                    printf("ID: %d, Title: %s, Year: %d, Sold: %s\n", artworks[j].id, artworks[j].title, artworks[j].year, artworks[j].isSold ? "Yes" : "No");
                }
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Artist with name %s not found.\n", name);
    }
}

void searchByExhibitionDate() {
    char date[20];
    int found = 0;
    printf("Enter Date (dd/mm/yyyy): ");
    scanf("%s", date);

    printf("\nArtworks Sold on %s:\n", date);
    for (int i = 0; i < artworkCount; i++) {
        if (artworks[i].isSold) {
            for (int j = 0; j < visitorCount; j++) {
                if (strcmp(visitors[j].visitDate, date) == 0) {
                    for (int k = 0; k < exhibitionCount; k++) {
                        if (visitors[j].exhibitionId == exhibitions[k].id) {
                            for (int l = 0; l < exhibitions[k].artworkCount; l++) {
                                if (artworks[i].id == exhibitions[k].artworkIds[l]) {
                                    printf("Artwork ID: %d, Title: %s, Year: %d, Exhibition: %s, Artist ID: %d\n", artworks[i].id, artworks[i].title, artworks[i].year, exhibitions[k].name, artworks[i].artistId);
                                    found = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (!found) {
        printf("No artworks sold on %s.\n", date);
    }
}

void generateReport() {
   int soldCount = 0, availableCount = 0;

    printf("\nReport:\n");
    printf("Number of artists: %d\n", artistCount);

    for (int i = 0; i < artistCount; i++) {
        printf("\nArtist: %s\n", artists[i].name);
        printf("Artworks:\n");

        for (int j = 0; j < artworkCount; j++) {
            if (artworks[j].artistId == artists[i].id) {
                printf("ID: %d, Title: %s, Year: %d, Sold: %s\n", artworks[j].id, artworks[j].title, artworks[j].year, artworks[j].isSold ? "Yes" : "No");
                if (artworks[j].isSold) {
                    soldCount++;
                } else {
                    availableCount++;
                }
            }
        }
    }

    printf("\nTotal artworks sold: %d\n", soldCount);
    printf("Total artworks available: %d\n", availableCount);
    printf("Number of exhibitions: %d\n", exhibitionCount);

    for (int i = 0; i < exhibitionCount; i++) {
        printf("\nExhibition: %s\n", exhibitions[i].name);
        printf("Sold Artworks: %d\n", exhibitions[i].soldArtworks);
    }

    printf("Number of visitors: %d\n", visitorCount);

    for (int i = 0; i < exhibitionCount; i++) {
        int visitorsInExhibition = 0;

        for (int j = 0; j < visitorCount; j++) {
            if (visitors[j].exhibitionId == exhibitions[i].id) {
                visitorsInExhibition++;
            }
        }

        printf("Exhibition: %s, Visitors: %d\n", exhibitions[i].name, visitorsInExhibition);
    }

}
void saveData() {
    FILE *fp;

    // Save artists data
    fp = fopen("artists.txt", "w");
    if (fp == NULL) {
        printf("Error opening file artists.txt for writing.\n");
        return;
    }
    for (int i = 0; i < artistCount; i++) {
        fprintf(fp, "%d %s %s\n", artists[i].id, artists[i].name, artists[i].nationality);
    }
    fclose(fp);

    // Save artworks data
    fp = fopen("artworks.txt", "w");
    if (fp == NULL) {
        printf("Error opening file artworks.txt for writing.\n");
        return;
    }
    for (int i = 0; i < artworkCount; i++) {
        fprintf(fp, "%d %s %d %d %d\n", artworks[i].id, artworks[i].title, artworks[i].year, artworks[i].artistId, artworks[i].isSold);
    }
    fclose(fp);

    // Save exhibitions data
    fp = fopen("exhibitions.txt", "w");
    if (fp == NULL) {
        printf("Error opening file exhibitions.txt for writing.\n");
        return;
    }
    for (int i = 0; i < exhibitionCount; i++) {
        fprintf(fp, "%d %s %s %s %d %d\n", exhibitions[i].id, exhibitions[i].name, exhibitions[i].startDate, exhibitions[i].endDate, exhibitions[i].artworkCount, exhibitions[i].soldArtworks);
        for (int j = 0; j < exhibitions[i].artworkCount; j++) {
            fprintf(fp, "%d ", exhibitions[i].artworkIds[j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    // Save visitors data
    fp = fopen("visitors.txt", "w");
    if (fp == NULL) {
        printf("Error opening file visitors.txt for writing.\n");
        return;
    }
    for (int i = 0; i < visitorCount; i++) {
        fprintf(fp, "%d %s %s %d\n", visitors[i].id, visitors[i].name, visitors[i].visitDate, visitors[i].exhibitionId);
    }
    fclose(fp);

    printf("Data saved successfully.\n");
}

void loadData() {
    FILE *fp;
    int id, year, artistId, isSold, artworkId, artworkCount, soldArtworks, exhibitionId;
    char name[50], nationality[30], title[50], startDate[20], endDate[20], visitDate[20];

    // Load artists data
    fp = fopen("artists.txt", "r");
    if (fp == NULL) {
        printf("Error opening file artists.txt for reading.\n");
        return;
    }
    artistCount = 0;
    while (fscanf(fp, "%d %s %s", &id, name, nationality) != EOF) {
        artists[artistCount].id = id;
        strcpy(artists[artistCount].name, name);
        strcpy(artists[artistCount].nationality, nationality);
        artistCount++;
    }
    fclose(fp);

    // Load artworks data
    fp = fopen("artworks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file artworks.txt for reading.\n");
        return;
    }
    artworkCount = 0;
    while (fscanf(fp, "%d %s %d %d %d", &id, title, &year, &artistId, &isSold) != EOF) {
        artworks[artworkCount].id = id;
        strcpy(artworks[artworkCount].title, title);
        artworks[artworkCount].year = year;
        artworks[artworkCount].artistId = artistId;
        artworks[artworkCount].isSold = isSold;
        artworkCount++;
    }
    fclose(fp);

    // Load exhibitions data
    fp = fopen("exhibitions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file exhibitions.txt for reading.\n");
        return;
    }
    exhibitionCount = 0;
    while (fscanf(fp, "%d %s %s %s %d %d", &id, name, startDate, endDate, &artworkCount, &soldArtworks) != EOF) {
        exhibitions[exhibitionCount].id = id;
        strcpy(exhibitions[exhibitionCount].name, name);
        strcpy(exhibitions[exhibitionCount].startDate, startDate);
        strcpy(exhibitions[exhibitionCount].endDate, endDate);
        exhibitions[exhibitionCount].artworkCount = artworkCount;
        exhibitions[exhibitionCount].soldArtworks = soldArtworks;
        for (int i = 0; i < artworkCount; i++) {
            fscanf(fp, "%d", &artworkId);
            exhibitions[exhibitionCount].artworkIds[i] = artworkId;
        }
        exhibitionCount++;
    }
    fclose(fp);

    // Load visitors data
    fp = fopen("visitors.txt", "r");
    if (fp == NULL) {
        printf("Error opening file visitors.txt for reading.\n");
        return;
    }
    visitorCount = 0;
    while (fscanf(fp, "%d %s %s %d", &id, name, visitDate, &exhibitionId) != EOF) {
        visitors[visitorCount].id = id;
        strcpy(visitors[visitorCount].name, name);
        strcpy(visitors[visitorCount].visitDate, visitDate);
        visitors[visitorCount].exhibitionId = exhibitionId;
        visitorCount++;
    }
    fclose(fp);

    printf("Data loaded successfully.\n");
}