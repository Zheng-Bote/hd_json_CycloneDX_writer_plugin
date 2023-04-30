/**
 * @file hd_json_CycloneDX_writer_plugin.cpp
 * @author ZHENG Robert (www.robert.hase-zheng.net)
 * @brief JSon CycloneDX (SPDX) writer plugin for header_docu
 * @details JSon array of JSon objects
 * @version 0.1.0
 * @date 2023-04-30
 *
 * @copyright Copyright (c) ZHENG Robert 2023
 *
 */

#include "hd_json_cyclonedx_writer_plugin.h"

const QString PLUGIN_SHORTNAME = "json_cyclonedx";
const QString PLUGIN_NAME = "json CycloneDX (spdx) writer";
const QString PLUGIN_VERSION = "0.1.0";

Hd_json_CycloneDX_writer_plugin::Hd_json_CycloneDX_writer_plugin(QObject *parent)
{
    Q_UNUSED(parent);
    //qDebug() << "Plugin Constructor";
}

Hd_json_CycloneDX_writer_plugin::~Hd_json_CycloneDX_writer_plugin()
{
    //qDebug() << "Plugin Deconstructed";
}

void Hd_json_CycloneDX_writer_plugin::test(QString name)
{
    qInfo() << "Test from " << PLUGIN_SHORTNAME << " Plugin: " << name;
}

QString Hd_json_CycloneDX_writer_plugin::getName()
{
    return PLUGIN_SHORTNAME;
}

QString Hd_json_CycloneDX_writer_plugin::getVersion()
{
    return PLUGIN_NAME + "-v" + PLUGIN_VERSION;
}

void Hd_json_CycloneDX_writer_plugin::parseFile(QMap<QString, QString> &mapParseKeys,
                                                QString pathToFile)
{}

void Hd_json_CycloneDX_writer_plugin::writeFile(QMap<QString, QString> mapParseKeys,
                                                QMap<QString, QString> mapFileAttribs,
                                                QString pathToFile)
{
    QFile file(pathToFile);
    QString jsonStr = "{}";
    QJsonDocument jDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    QJsonObject jSub;
    QJsonObject jSub2;
    QJsonObject jObj = jDoc.object();
    QJsonObject jObj2 = jDoc.object();
    QJsonArray jArr{};
    QJsonArray jArr2{};

    /*
    for (auto [key, val] : mapFileAttribs.asKeyValueRange()) {
        jSub[key] = val;
    }
    for (auto [key, val] : mapParseKeys.asKeyValueRange()) {
        jSub[key] = val.trimmed();
    }
*/

    jObj["bomFormat"] = "CycloneDX";
    jObj["specVersion"] = "1.4";
    jObj["serialNumber"] = "urn:uuid:3e671687-395b-41f5-a30f-a58921a69b79";
    jObj["version"] = "1";
    /*
    jObj2["created"] = mapFileAttribs["FILE_Scan_UTCcurrent"];
    jObj2["creators"] = "System: fileheader docu (robert.hase-zheng.net)";
    jObj["creationInfo"] = jObj2;
    jArr.append(jObj);

    jObj = jDoc.object();
    jObj["name"] = mapFileAttribs["FILE_Name"];
    jObj["documentNamespace"] = mapFileAttribs["FILE_absolutePath"];
    jObj["documentDescribes"] = mapParseKeys["BRIEF"].trimmed();
    jArr.append(jObj);

    jObj = jDoc.object();
*/
    jSub = QJsonObject();
    jSub["type"] = mapParseKeys["TYPE"].trimmed();
    jSub["name"] = mapFileAttribs["FILE_Name"].trimmed();
    jSub["version"] = mapParseKeys["VERSION"].trimmed();
    jSub["purl"] = mapParseKeys["SOURCE"].trimmed();

    jObj2 = jDoc.object();
    jArr2 = QJsonArray();
    jObj2["alg"] = "SHA256";
    jObj2["content"] = mapFileAttribs["FILE_SHA256_Hash"];
    jArr2.append(jObj2);
    jSub["hashes"] = jArr2;

    jObj2 = jDoc.object();
    jArr2 = QJsonArray();
    jObj2["expression"] = mapParseKeys["LICENSE"].trimmed();
    jArr2.append(jObj2);
    jSub["licenses"] = jArr2;

    jObj2 = jDoc.object();
    jArr2 = QJsonArray();
    jObj2["name"] = mapParseKeys["AUTHOR"].trimmed();
    jObj2["email"] = mapParseKeys["EMAIL"].trimmed();
    jSub["contact"] = jObj2;
    jArr2.append(jObj2);
    jSub["contact"] = jArr2;

    jObj2 = jDoc.object();
    jArr2 = QJsonArray();
    jSub2 = QJsonObject();
    jSub2["name"] = "BRIEF";
    jSub2["value"] = mapParseKeys["BRIEF"].trimmed();
    jArr2.append(jSub2);
    jSub2 = QJsonObject();
    jSub2["name"] = "DESC";
    jSub2["value"] = mapParseKeys["DESC"].trimmed();
    jArr2.append(jSub2);
    jSub2 = QJsonObject();
    jSub2["name"] = "COMMENT";
    jSub2["value"] = mapParseKeys["COMMENT"].trimmed();
    jArr2.append(jSub2);
    jSub2 = QJsonObject();
    jSub2["name"] = "FILE_LastModified_localtime";
    jSub2["value"] = mapFileAttribs["FILE_LastModified_localtime"].trimmed();
    jArr2.append(jSub2);
    jSub2 = QJsonObject();
    jSub2["name"] = "FILE_Perm_AlphaNumeric";
    jSub2["value"] = mapFileAttribs["FILE_Perm_AlphaNumeric"].trimmed();
    jArr2.append(jSub2);
    jSub2 = QJsonObject();
    jSub2["name"] = "FILE_Perm_Numeric";
    jSub2["value"] = mapFileAttribs["FILE_Perm_Numeric"].trimmed();
    jArr2.append(jSub2);
    jSub2 = QJsonObject();
    jSub2["name"] = "FILE_Scan_UTCcurrent";
    jSub2["value"] = mapFileAttribs["FILE_Scan_UTCcurrent"].trimmed();
    jArr2.append(jSub2);
    jSub2 = QJsonObject();
    jSub2["name"] = "FILE_Size";
    jSub2["value"] = mapFileAttribs["FILE_Size"].trimmed();
    jArr2.append(jSub2);
    jSub2 = QJsonObject();
    jSub2["name"] = "FILE_absolutePath";
    jSub2["value"] = mapFileAttribs["FILE_absolutePath"].trimmed();
    jArr2.append(jSub2);
    jSub2 = QJsonObject();
    jSub2["name"] = "FILE_baseDirName";
    jSub2["value"] = mapFileAttribs["FILE_baseDirName"].trimmed();
    jArr2.append(jSub2);
    jArr2.append(jSub2);
    jSub2 = QJsonObject();
    jSub2["name"] = "FILE_lastModified_humanUTC";
    jSub2["value"] = mapFileAttribs["FILE_lastModified_humanUTC"].trimmed();
    jArr2.append(jSub2);
    jObj2["properties"] = jArr2;
    jSub["metadata"] = jObj2;

    jSub["author"] = mapParseKeys["AUTHOR"].trimmed();
    jArr.append(jSub);
    // ###

    jObj["components"] = jArr;
    jDoc.setObject(jObj);
    //jDoc.setArray(jArr);

    /*
    
    jSub["SPDXID"] = "SPDXRef-" + mapParseKeys["TITLE"].trimmed();
    
    jSub["downloadLocation"] = mapParseKeys["SOURCE"].trimmed();
    jSub["packageVersion"] = mapParseKeys["VERSION"].trimmed();
    jSub["noticeText"] = mapParseKeys["BRIEF"].trimmed();
    jSub["comment"] = mapParseKeys["DESC"].trimmed();
    jSub["filesAnalyzed"] = "false";

    jObj2 = jDoc.object();
    jObj2["algorithmen"] = "SHA256";
    jObj2["checksumValue"] = mapFileAttribs["FILE_SHA256_Hash"];
    jSub["checksums"] = jObj2;
    jSub["packageLicenseConcluded"] = "NOASSERTION";
    jSub["packageLicenseDeclared"] = mapParseKeys["LICENSE"].trimmed();
    jSub["packageCopyRightText"] = mapParseKeys["COPYRIGHT"].trimmed();

    jObj["components"] = jSub;
*/

    // jArr.append(jObj);
    // jDoc.setArray(jArr);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << jDoc.toJson();
        file.close();
    }
}
