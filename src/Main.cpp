#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <MtpServer.h>
#include <MtpStorage.h>
#include <MtpObjectInfo.h>
#include <MtpDatabase.h>
//TODO
#define printf printf

using namespace android;

#define AID_MEDIA_RW      1023  /* internal media storage write access */
#define AID_MTP           1024  /* MTP USB driver access */

namespace android {
extern void initialize_string8();
extern void terminate_string8();
}

static Mutex sMutex;

class MyMtpDatabase : public MtpDatabase
{
public:

    MyMtpDatabase();

    virtual                         ~MyMtpDatabase();
    void                            cleanup();

    virtual MtpObjectHandle         beginSendObject(const char* path,
                                            MtpObjectFormat format,
                                            MtpObjectHandle parent,
                                            MtpStorageID storage,
                                            uint64_t size,
                                            time_t modified);

    virtual void                    endSendObject(const char* path,
                                            MtpObjectHandle handle,
                                            MtpObjectFormat format,
                                            bool succeeded);

    virtual MtpObjectHandleList*    getObjectList(MtpStorageID storageID,
                                    MtpObjectFormat format,
                                    MtpObjectHandle parent);

    virtual int                     getNumObjects(MtpStorageID storageID,
                                            MtpObjectFormat format,
                                            MtpObjectHandle parent);

    // callee should delete[] the results from these
    // results can be NULL
    virtual MtpObjectFormatList*    getSupportedPlaybackFormats();
    virtual MtpObjectFormatList*    getSupportedCaptureFormats();
    virtual MtpObjectPropertyList*  getSupportedObjectProperties(MtpObjectFormat format);
    virtual MtpDevicePropertyList*  getSupportedDeviceProperties();

    virtual MtpResponseCode         getObjectPropertyValue(MtpObjectHandle handle,
                                            MtpObjectProperty property,
                                            MtpDataPacket& packet);

    virtual MtpResponseCode         setObjectPropertyValue(MtpObjectHandle handle,
                                            MtpObjectProperty property,
                                            MtpDataPacket& packet);

    virtual MtpResponseCode         getDevicePropertyValue(MtpDeviceProperty property,
                                            MtpDataPacket& packet);

    virtual MtpResponseCode         setDevicePropertyValue(MtpDeviceProperty property,
                                            MtpDataPacket& packet);

    virtual MtpResponseCode         resetDeviceProperty(MtpDeviceProperty property);

    virtual MtpResponseCode         getObjectPropertyList(MtpObjectHandle handle,
                                            uint32_t format, uint32_t property,
                                            int groupCode, int depth,
                                            MtpDataPacket& packet);

    virtual MtpResponseCode         getObjectInfo(MtpObjectHandle handle,
                                            MtpObjectInfo& info);

    virtual void*                   getThumbnail(MtpObjectHandle handle, size_t& outThumbSize);

    virtual MtpResponseCode         getObjectFilePath(MtpObjectHandle handle,
                                            MtpString& outFilePath,
                                            int64_t& outFileLength,
                                            MtpObjectFormat& outFormat);
    virtual MtpResponseCode         deleteFile(MtpObjectHandle handle);

    bool                            getObjectPropertyInfo(MtpObjectProperty property, int& type);
    bool                            getDevicePropertyInfo(MtpDeviceProperty property, int& type);

    virtual MtpObjectHandleList*    getObjectReferences(MtpObjectHandle handle);

    virtual MtpResponseCode         setObjectReferences(MtpObjectHandle handle,
                                            MtpObjectHandleList* references);

    virtual MtpProperty*            getObjectPropertyDesc(MtpObjectProperty property,
                                            MtpObjectFormat format);

    virtual MtpProperty*            getDevicePropertyDesc(MtpDeviceProperty property);

    virtual void                    sessionStarted();

    virtual void                    sessionEnded();

private:

};

MyMtpDatabase::MyMtpDatabase()
{
}

void MyMtpDatabase::cleanup()
{
}

MyMtpDatabase::~MyMtpDatabase() {
}

MtpObjectHandle MyMtpDatabase::beginSendObject(const char* path,
                                            MtpObjectFormat format,
                                            MtpObjectHandle parent,
                                            MtpStorageID storage,
                                            uint64_t size,
                                            time_t modified) {
    MtpObjectHandle result;
    return result;
}

void MyMtpDatabase::endSendObject(const char* path, MtpObjectHandle handle,
                                MtpObjectFormat format, bool succeeded) {
}


MtpObjectHandleList* MyMtpDatabase::getObjectList(MtpStorageID storageID,
                                    MtpObjectFormat format,
                                    MtpObjectHandle parent) {
    MtpObjectHandleList* list = new MtpObjectHandleList();
    return list;
}

int MyMtpDatabase::getNumObjects(MtpStorageID storageID,
                                MtpObjectFormat format,
                                MtpObjectHandle parent) {
    int result;
    return result;
}

MtpObjectFormatList* MyMtpDatabase::getSupportedPlaybackFormats() {
    MtpObjectFormatList* list = new MtpObjectFormatList();
    return list;
}

MtpObjectFormatList* MyMtpDatabase::getSupportedCaptureFormats() {
    MtpObjectFormatList* list = new MtpObjectFormatList();
    return list;
}

MtpObjectPropertyList* MyMtpDatabase::getSupportedObjectProperties(MtpObjectFormat format) {
    MtpObjectPropertyList* list = new MtpObjectPropertyList();
    return list;
}

MtpDevicePropertyList* MyMtpDatabase::getSupportedDeviceProperties() {
    MtpDevicePropertyList* list = new MtpDevicePropertyList();
    return list;
}

MtpResponseCode MyMtpDatabase::getObjectPropertyValue(MtpObjectHandle handle,
                                            MtpObjectProperty property,
                                            MtpDataPacket& packet) {
    MtpResponseCode result;
    return result;
}

MtpResponseCode MyMtpDatabase::setObjectPropertyValue(MtpObjectHandle handle,
                                            MtpObjectProperty property,
                                            MtpDataPacket& packet) {
    MtpResponseCode result;
    return result;
}

MtpResponseCode MyMtpDatabase::getDevicePropertyValue(MtpDeviceProperty property,
                                            MtpDataPacket& packet) {
    return MTP_RESPONSE_OK;
}

MtpResponseCode MyMtpDatabase::setDevicePropertyValue(MtpDeviceProperty property,
                                            MtpDataPacket& packet) {
    return MTP_RESPONSE_OK;
}

MtpResponseCode MyMtpDatabase::resetDeviceProperty(MtpDeviceProperty property) {
    return -1;
}

MtpResponseCode MyMtpDatabase::getObjectPropertyList(MtpObjectHandle handle,
                                            uint32_t format, uint32_t property,
                                            int groupCode, int depth,
                                            MtpDataPacket& packet) {
    return MTP_RESPONSE_OK;
}

MtpResponseCode MyMtpDatabase::getObjectInfo(MtpObjectHandle handle,
                                            MtpObjectInfo& info) {
    return MTP_RESPONSE_OK;
}

void* MyMtpDatabase::getThumbnail(MtpObjectHandle handle, size_t& outThumbSize) {
    return NULL;
}

MtpResponseCode MyMtpDatabase::getObjectFilePath(MtpObjectHandle handle,
                                            MtpString& outFilePath,
                                            int64_t& outFileLength,
                                            MtpObjectFormat& outFormat) {
    return MTP_RESPONSE_OK;
}

MtpResponseCode MyMtpDatabase::deleteFile(MtpObjectHandle handle) {
    return MTP_RESPONSE_OK;
}

struct PropertyTableEntry {
    MtpObjectProperty   property;
    int                 type;
};

static const PropertyTableEntry   kObjectPropertyTable[] = {
    {   MTP_PROPERTY_STORAGE_ID,        MTP_TYPE_UINT32     },
    {   MTP_PROPERTY_OBJECT_FORMAT,     MTP_TYPE_UINT16     },
    {   MTP_PROPERTY_PROTECTION_STATUS, MTP_TYPE_UINT16     },
    {   MTP_PROPERTY_OBJECT_SIZE,       MTP_TYPE_UINT64     },
    {   MTP_PROPERTY_OBJECT_FILE_NAME,  MTP_TYPE_STR        },
    {   MTP_PROPERTY_DATE_MODIFIED,     MTP_TYPE_STR        },
    {   MTP_PROPERTY_PARENT_OBJECT,     MTP_TYPE_UINT32     },
    {   MTP_PROPERTY_PERSISTENT_UID,    MTP_TYPE_UINT128    },
    {   MTP_PROPERTY_NAME,              MTP_TYPE_STR        },
    {   MTP_PROPERTY_DISPLAY_NAME,      MTP_TYPE_STR        },
    {   MTP_PROPERTY_DATE_ADDED,        MTP_TYPE_STR        },
    {   MTP_PROPERTY_ARTIST,            MTP_TYPE_STR        },
    {   MTP_PROPERTY_ALBUM_NAME,        MTP_TYPE_STR        },
    {   MTP_PROPERTY_ALBUM_ARTIST,      MTP_TYPE_STR        },
    {   MTP_PROPERTY_TRACK,             MTP_TYPE_UINT16     },
    {   MTP_PROPERTY_ORIGINAL_RELEASE_DATE, MTP_TYPE_STR    },
    {   MTP_PROPERTY_GENRE,             MTP_TYPE_STR        },
    {   MTP_PROPERTY_COMPOSER,          MTP_TYPE_STR        },
    {   MTP_PROPERTY_DURATION,          MTP_TYPE_UINT32     },
    {   MTP_PROPERTY_DESCRIPTION,       MTP_TYPE_STR        },
};

static const PropertyTableEntry   kDevicePropertyTable[] = {
    {   MTP_DEVICE_PROPERTY_SYNCHRONIZATION_PARTNER,    MTP_TYPE_STR },
    {   MTP_DEVICE_PROPERTY_DEVICE_FRIENDLY_NAME,       MTP_TYPE_STR },
    {   MTP_DEVICE_PROPERTY_IMAGE_SIZE,                 MTP_TYPE_STR },
};

bool MyMtpDatabase::getObjectPropertyInfo(MtpObjectProperty property, int& type) {
    return false;
}

bool MyMtpDatabase::getDevicePropertyInfo(MtpDeviceProperty property, int& type) {
    return false;
}

MtpObjectHandleList* MyMtpDatabase::getObjectReferences(MtpObjectHandle handle) {
    MtpObjectHandleList* list = new MtpObjectHandleList();
    return list;
}

MtpResponseCode MyMtpDatabase::setObjectReferences(MtpObjectHandle handle,
                                                    MtpObjectHandleList* references) {
    return MTP_RESPONSE_OK;
}

MtpProperty* MyMtpDatabase::getObjectPropertyDesc(MtpObjectProperty property,
                                            MtpObjectFormat format) {
    MtpProperty* result = NULL;
    return result;
}

MtpProperty* MyMtpDatabase::getDevicePropertyDesc(MtpDeviceProperty property) {
    MtpProperty* result = NULL;
    return result;
}

void MyMtpDatabase::sessionStarted() {
}

void MyMtpDatabase::sessionEnded() {
}

// ----------------------------------------------------------------------------

static MtpServer * MtpServer_setup(MtpDatabase * myDatabase, bool usePtp)
{
    int fd = open("/dev/mtp_usb", O_RDWR);
    if (fd >= 0) {
        MtpServer* server = new MtpServer(fd, myDatabase,
                usePtp, AID_MEDIA_RW, 0664, 0775);
        return server;
    } else {
        printf("could not open MTP driver, errno: %d", errno);
        return NULL;
    }
}

static void MtpServer_run(MtpServer * server)
{
    if (server)
        server->run();
    else
        printf("server is null in run");
}

static void MtpServer_cleanup(MtpServer * server)
{
    Mutex::Autolock autoLock(sMutex);

    if (server) {
        delete server;
    } else {
        printf("server is null in cleanup");
    }
}

static void MtpServer_add_storage(MtpServer * server, int storageId)
{
    Mutex::Autolock autoLock(sMutex);

    if (server) {
        char * path = "/home";
        char * description = "Hello MTP";
        long reserveSpace = 1024;
        bool removable = true;
        long maxFileSize = 1024;
        MtpStorage* storage = new MtpStorage(storageId, path, description,
            reserveSpace, removable, maxFileSize);
        server->addStorage(storage);
    } else {
        printf("server is null in add_storage");
    }
}

static void MtpServer_remove_storage(MtpServer * server, int storageId)
{
    Mutex::Autolock autoLock(sMutex);

    if (server) {
        MtpStorage* storage = server->getStorage(storageId);
        if (storage) {
            server->removeStorage(storage);
            delete storage;
        }
    } else
        printf("server is null in remove_storage");
}



int main(int argc, char * argv[])
{
    printf("Hello MTP\n");
    initialize_string8();

    MyMtpDatabase * database = new MyMtpDatabase();
    MtpServer * server = MtpServer_setup(reinterpret_cast<MtpDatabase*>(database), false);
    printf("%x\n", server);
    if(!server)
    {
        printf("Failed to create a MTP server\n");
        return -1;
    }
    MtpServer_add_storage(server, 0x10001);
    MtpServer_run(server);

    terminate_string8();
    return 0;
}
