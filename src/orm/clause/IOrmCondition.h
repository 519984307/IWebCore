﻿#pragma once

#include "base/IHeaderUtil.h"
#include <cstdint>

$PackageWebCoreBegin

class ISqlQuery;
class IOrmDialectWare;
class IOrmConditionImpl;

class IOrmCondition
{
public:
    // NOTE: 这里需要注意在同一语句中 and or 和 not 的优先级, 在写文档的时候需要写进去
    enum Relation : uint8_t{
        And_Type,
        Or_Type,
    };

    enum Type : uint8_t{
        Where_Clause    = 1 << 0,
        OrderBy_Clause  = 1 << 1,
        GroupBy_Clause  = 1 << 2,
        Having_Clause   = 1 << 3,
        Limit_Clause    = 1 << 4,
        Default         = Where_Clause | OrderBy_Clause | Limit_Clause,
        ALL             = 0xFF
    };

    IOrmCondition();
    ~IOrmCondition() = default;

    IOrmCondition& where(const QString& clause);

//    template<typename T>
//    IOrmCondition& whereIn(const QString& field, const QList<T>& range, Relation relation = And_Type);

    IOrmCondition& whereIn(const QString& field, const QList<qint8>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<quint8>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<qint16>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<quint16>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<qint32>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<quint32>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<quint64>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<qint64>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<float>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<double>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<QString>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<QVariant>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<QDate>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<QTime>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QList<QDateTime>& range, Relation relation = And_Type);
    IOrmCondition& whereIn(const QString& field, const QStringList& range, Relation relation = And_Type);

    IOrmCondition& whereBetween(const QString& field, const QPair<qint8, qint8>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<quint8, quint8>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<qint16, qint16>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<quint16, quint16>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<qint32, qint32>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<quint32, quint32>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<qint64, qint64>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<quint64, quint64>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<float, float>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<double, double>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<QString, QString>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<QVariant, QVariant>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<QDate, QDate>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<QTime, QTime>& range, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, const QPair<QDateTime, QDateTime>& range, Relation relation = And_Type);

//    IOrmCondition& whereBetween(const QString& field, qint8 lowerBound, qint8 upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, quint8 lowerBound, quint8 upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, qint16 lowerBound, qint16 upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, quint16 lowerBound, quint16 upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, qint32 lowerBound, qint32 upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, quint32 lowerBound, quint32 upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, qint64 lowerBound, qint64 upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, quint64 lowerBound, quint64 upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, float lowerBound, float upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, double lowerBound, double upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, QString lowerBound, QString upperBound, Relation relation = And_Type);
    IOrmCondition& whereBetween(const QString& field, QVariant lowerBound, QVariant upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, QDate lowerBound, QDate upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, QTime lowerBound, QTime upperBound, Relation relation = And_Type);
//    IOrmCondition& whereBetween(const QString& field, QDateTime lowerBound, QDateTime upperBound, Relation relation = And_Type);


    IOrmCondition& whereLike(const QString& field, const QString& value, Relation relation = And_Type);

    IOrmCondition& whereEndWith(const QString& field, const QString& value, Relation relation = And_Type);

    IOrmCondition& whereStartWith(const QString& field, const QString& value, Relation relation = And_Type);

    IOrmCondition& whereContain(const QString& field, const QString& value, Relation relation = And_Type);

    IOrmCondition& whereNotLike(const QString& field, const QString& value, Relation relation = And_Type);

    IOrmCondition& whereIsNull(const QString& field, Relation relation = And_Type);

    IOrmCondition& whereIsNotNull(const QString& field, Relation relation = And_Type);

    IOrmCondition& whereEqual(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& whereNotEqual(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& whereLessThan(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& whereLessEqual(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& whereGreatThan(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& whereGreatEqual(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& whereTrue();

    IOrmCondition& whereFalse();

    IOrmCondition& conditionAnd(IOrmCondition condition);

    IOrmCondition& conditionOr(IOrmCondition condition);

    IOrmCondition& conditionAndNot(IOrmCondition condition);

    IOrmCondition& conditionOrNot(IOrmCondition condition);

    static
    IOrmCondition& conditionNot(IOrmCondition& condition);

    IOrmCondition& orderByAsc(const QString& field);

    IOrmCondition& orderByDesc(const QString& field);

    IOrmCondition& groupBy(const QString& field);

    //! @note this is not field. its clause
    IOrmCondition& having(const QString& clause);

    IOrmCondition& havingIn(const QString& field, const QList<qint8>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<quint8>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<qint16>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<quint16>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<qint32>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<quint32>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<quint64>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<qint64>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<float>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<double>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<QString>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<QVariant>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<QDate>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<QTime>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QList<QDateTime>& range, Relation relation = And_Type);
    IOrmCondition& havingIn(const QString& field, const QStringList& range, Relation relation = And_Type);

    IOrmCondition& havingBetween(const QString& field, const QPair<qint8, qint8>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<quint8, quint8>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<qint16, qint16>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<quint16, quint16>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<qint32, qint32>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<quint32, quint32>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<qint64, qint64>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<quint64, quint64>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<float, float>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<double, double>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<QString, QString>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<QVariant, QVariant>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<QDate, QDate>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<QTime, QTime>& range, Relation relation = And_Type);
    IOrmCondition& havingBetween(const QString& field, const QPair<QDateTime, QDateTime>& range, Relation relation = And_Type);

    IOrmCondition& havingEqual(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& havingNotEqual(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& havingLessThan(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& havingLessEqual(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& havingGreatThan(const QString& field, const QVariant& value, Relation relation = And_Type);

    IOrmCondition& havingGreatEqual(const QString& field, const QVariant& value, Relation relation = And_Type);

//    IOrmCondition& havingLike(const QString& field, const QString& value, Relation relation = And_Type);

//    IOrmCondition& havingEndWith(const QString& field, const QString& value, Relation relation = And_Type);

//    IOrmCondition& havingStartWith(const QString& field, const QString& value, Relation relation = And_Type);

//    IOrmCondition& havingContain(const QString& field, const QString& value, Relation relation = And_Type);

//    IOrmCondition& havingNotLike(const QString& field, const QString& value, Relation relation = And_Type);

//    IOrmCondition& havingIsNull(const QString& field, Relation relation = And_Type);

//    IOrmCondition& havingIsNotNull(const QString& field, Relation relation = And_Type);

    IOrmCondition& limit(IOrmDialectWare* dialect, quint64 count);

    IOrmCondition& limit(IOrmDialectWare* dialect, quint64 start, quint64 count);

    QString toSql(Type types = IOrmCondition::Default) const;

    QString toWhereClause() const;
    QString toOrderByClause() const;
    QString toGroupByClause() const;
    QString toLimitClause() const;
    QString toHavingClause() const;

    QMap<QString, QVariant> getParameters() const;  // only for test use
    void bindParameters(ISqlQuery& query) const;
    void bindParameters(QSqlQuery& query) const;
    bool isValid() const;

private:
    friend class IOrmConditionImpl;
    std::shared_ptr<IOrmConditionImpl> impl;
};


//namespace IOrmConditionHelper{
//    template<typename T>
//    void whereIn(std::shared_ptr<IOrmConditionImpl> impl, const QString& field, const QList<T>& range, IOrmCondition::Relation relation = IOrmCondition::And_Type);
//    void whereIn(std::shared_ptr<IOrmConditionImpl> impl, const QString& field, const QStringList& range, IOrmCondition::Relation relation = IOrmCondition::And_Type);


//}

//template<typename T>
//IOrmCondition& IOrmCondition::whereIn(const QString& field, const QList<T>& range, IOrmCondition::Relation relation)
//{
//    IOrmConditionHelper::whereIn(impl, field, range, relation);
//    return *this;
//}

#define $Cdt IOrmCondition()

$PackageWebCoreEnd
