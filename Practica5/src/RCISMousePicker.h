//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.4
//
// <auto-generated>
//
// Generated from file `RCISMousePicker.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __RCISMousePicker_h__
#define __RCISMousePicker_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/GCObject.h>
#include <Ice/Value.h>
#include <Ice/Incoming.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/Optional.h>
#include <IceUtil/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 >= 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 4
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace RoboCompRCISMousePicker
{

class RCISMousePicker;
class RCISMousePickerPrx;

}

namespace RoboCompRCISMousePicker
{

struct Pick
{
    ::std::string objectName;
    float x;
    float y;
    float z;

    /**
     * Obtains a tuple containing all of the struct's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&, const float&, const float&, const float&> ice_tuple() const
    {
        return std::tie(objectName, x, y, z);
    }
};

using Ice::operator<;
using Ice::operator<=;
using Ice::operator>;
using Ice::operator>=;
using Ice::operator==;
using Ice::operator!=;

}

namespace RoboCompRCISMousePicker
{

class RCISMousePicker : public virtual ::Ice::Object
{
public:

    using ProxyType = RCISMousePickerPrx;

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(::std::string id, const ::Ice::Current& current) const override;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector<::std::string> ice_ids(const ::Ice::Current& current) const override;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual ::std::string ice_id(const ::Ice::Current& current) const override;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual void setPick(Pick myPick, const ::Ice::Current& current) = 0;
    /// \cond INTERNAL
    bool _iceD_setPick(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&) override;
    /// \endcond
};

}

namespace RoboCompRCISMousePicker
{

class RCISMousePickerPrx : public virtual ::Ice::Proxy<RCISMousePickerPrx, ::Ice::ObjectPrx>
{
public:

    void setPick(const Pick& myPick, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        _makePromiseOutgoing<void>(true, this, &RCISMousePickerPrx::_iceI_setPick, myPick, context).get();
    }

    template<template<typename> class P = ::std::promise>
    auto setPickAsync(const Pick& myPick, const ::Ice::Context& context = ::Ice::noExplicitContext)
        -> decltype(::std::declval<P<void>>().get_future())
    {
        return _makePromiseOutgoing<void, P>(false, this, &RCISMousePickerPrx::_iceI_setPick, myPick, context);
    }

    ::std::function<void()>
    setPickAsync(const Pick& myPick,
                 ::std::function<void()> response,
                 ::std::function<void(::std::exception_ptr)> ex = nullptr,
                 ::std::function<void(bool)> sent = nullptr,
                 const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _makeLamdaOutgoing<void>(std::move(response), std::move(ex), std::move(sent), this, &RoboCompRCISMousePicker::RCISMousePickerPrx::_iceI_setPick, myPick, context);
    }

    /// \cond INTERNAL
    void _iceI_setPick(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>&, const Pick&, const ::Ice::Context&);
    /// \endcond

    /**
     * Obtains the Slice type ID of this interface.
     * @return The fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:

    /// \cond INTERNAL
    RCISMousePickerPrx() = default;
    friend ::std::shared_ptr<RCISMousePickerPrx> IceInternal::createProxy<RCISMousePickerPrx>();

    virtual ::std::shared_ptr<::Ice::ObjectPrx> _newInstance() const override;
    /// \endcond
};

}

/// \cond STREAM
namespace Ice
{

template<>
struct StreamableTraits<::RoboCompRCISMousePicker::Pick>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 13;
    static const bool fixedLength = false;
};

template<typename S>
struct StreamReader<::RoboCompRCISMousePicker::Pick, S>
{
    static void read(S* istr, ::RoboCompRCISMousePicker::Pick& v)
    {
        istr->readAll(v.objectName, v.x, v.y, v.z);
    }
};

}
/// \endcond

/// \cond INTERNAL
namespace RoboCompRCISMousePicker
{

using RCISMousePickerPtr = ::std::shared_ptr<RCISMousePicker>;
using RCISMousePickerPrxPtr = ::std::shared_ptr<RCISMousePickerPrx>;

}
/// \endcond

#else // C++98 mapping

namespace IceProxy
{

namespace RoboCompRCISMousePicker
{

class RCISMousePicker;
/// \cond INTERNAL
void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< RCISMousePicker>&);
::IceProxy::Ice::Object* upCast(RCISMousePicker*);
/// \endcond

}

}

namespace RoboCompRCISMousePicker
{

class RCISMousePicker;
/// \cond INTERNAL
::Ice::Object* upCast(RCISMousePicker*);
/// \endcond
typedef ::IceInternal::Handle< RCISMousePicker> RCISMousePickerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::RoboCompRCISMousePicker::RCISMousePicker> RCISMousePickerPrx;
typedef RCISMousePickerPrx RCISMousePickerPrxPtr;
/// \cond INTERNAL
void _icePatchObjectPtr(RCISMousePickerPtr&, const ::Ice::ObjectPtr&);
/// \endcond

}

namespace RoboCompRCISMousePicker
{

struct Pick
{
    ::std::string objectName;
    ::Ice::Float x;
    ::Ice::Float y;
    ::Ice::Float z;
};

}

namespace RoboCompRCISMousePicker
{

/**
 * Base class for asynchronous callback wrapper classes used for calls to
 * IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 * Create a wrapper instance by calling ::RoboCompRCISMousePicker::newCallback_RCISMousePicker_setPick.
 */
class Callback_RCISMousePicker_setPick_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_RCISMousePicker_setPick_Base> Callback_RCISMousePicker_setPickPtr;

}

namespace IceProxy
{

namespace RoboCompRCISMousePicker
{

class RCISMousePicker : public virtual ::Ice::Proxy<RCISMousePicker, ::IceProxy::Ice::Object>
{
public:

    void setPick(const ::RoboCompRCISMousePicker::Pick& myPick, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_setPick(_iceI_begin_setPick(myPick, context, ::IceInternal::dummyCallback, 0, true));
    }

    ::Ice::AsyncResultPtr begin_setPick(const ::RoboCompRCISMousePicker::Pick& myPick, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_setPick(myPick, context, ::IceInternal::dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_setPick(const ::RoboCompRCISMousePicker::Pick& myPick, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_setPick(myPick, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_setPick(const ::RoboCompRCISMousePicker::Pick& myPick, const ::Ice::Context& context, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_setPick(myPick, context, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_setPick(const ::RoboCompRCISMousePicker::Pick& myPick, const ::RoboCompRCISMousePicker::Callback_RCISMousePicker_setPickPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_setPick(myPick, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_setPick(const ::RoboCompRCISMousePicker::Pick& myPick, const ::Ice::Context& context, const ::RoboCompRCISMousePicker::Callback_RCISMousePicker_setPickPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_setPick(myPick, context, cb, cookie);
    }

    void end_setPick(const ::Ice::AsyncResultPtr& result);

private:

    ::Ice::AsyncResultPtr _iceI_begin_setPick(const ::RoboCompRCISMousePicker::Pick&, const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    /**
     * Obtains the Slice type ID corresponding to this interface.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:
    /// \cond INTERNAL

    virtual ::IceProxy::Ice::Object* _newInstance() const;
    /// \endcond
};

}

}

namespace RoboCompRCISMousePicker
{

class RCISMousePicker : public virtual ::Ice::Object
{
public:

    typedef RCISMousePickerPrx ProxyType;
    typedef RCISMousePickerPtr PointerType;

    virtual ~RCISMousePicker();

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(const ::std::string& id, const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual const ::std::string& ice_id(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual void setPick(const Pick& myPick, const ::Ice::Current& current = ::Ice::emptyCurrent) = 0;
    /// \cond INTERNAL
    bool _iceD_setPick(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

protected:

    /// \cond STREAM
    virtual void _iceWriteImpl(::Ice::OutputStream*) const;
    virtual void _iceReadImpl(::Ice::InputStream*);
    /// \endcond
};

/// \cond INTERNAL
inline bool operator==(const RCISMousePicker& lhs, const RCISMousePicker& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) == static_cast<const ::Ice::Object&>(rhs);
}

inline bool operator<(const RCISMousePicker& lhs, const RCISMousePicker& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) < static_cast<const ::Ice::Object&>(rhs);
}
/// \endcond

}

/// \cond STREAM
namespace Ice
{

template<>
struct StreamableTraits< ::RoboCompRCISMousePicker::Pick>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 13;
    static const bool fixedLength = false;
};

template<typename S>
struct StreamWriter< ::RoboCompRCISMousePicker::Pick, S>
{
    static void write(S* ostr, const ::RoboCompRCISMousePicker::Pick& v)
    {
        ostr->write(v.objectName);
        ostr->write(v.x);
        ostr->write(v.y);
        ostr->write(v.z);
    }
};

template<typename S>
struct StreamReader< ::RoboCompRCISMousePicker::Pick, S>
{
    static void read(S* istr, ::RoboCompRCISMousePicker::Pick& v)
    {
        istr->read(v.objectName);
        istr->read(v.x);
        istr->read(v.y);
        istr->read(v.z);
    }
};

}
/// \endcond

namespace RoboCompRCISMousePicker
{

/**
 * Type-safe asynchronous callback wrapper class used for calls to
 * IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 * Create a wrapper instance by calling ::RoboCompRCISMousePicker::newCallback_RCISMousePicker_setPick.
 */
template<class T>
class CallbackNC_RCISMousePicker_setPick : public Callback_RCISMousePicker_setPick_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_RCISMousePicker_setPick(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 */
template<class T> Callback_RCISMousePicker_setPickPtr
newCallback_RCISMousePicker_setPick(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_RCISMousePicker_setPick<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 */
template<class T> Callback_RCISMousePicker_setPickPtr
newCallback_RCISMousePicker_setPick(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_RCISMousePicker_setPick<T>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 */
template<class T> Callback_RCISMousePicker_setPickPtr
newCallback_RCISMousePicker_setPick(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_RCISMousePicker_setPick<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 */
template<class T> Callback_RCISMousePicker_setPickPtr
newCallback_RCISMousePicker_setPick(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_RCISMousePicker_setPick<T>(instance, 0, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class with cookie support used for calls to
 * IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 * Create a wrapper instance by calling ::RoboCompRCISMousePicker::newCallback_RCISMousePicker_setPick.
 */
template<class T, typename CT>
class Callback_RCISMousePicker_setPick : public Callback_RCISMousePicker_setPick_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_RCISMousePicker_setPick(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 */
template<class T, typename CT> Callback_RCISMousePicker_setPickPtr
newCallback_RCISMousePicker_setPick(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_RCISMousePicker_setPick<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 */
template<class T, typename CT> Callback_RCISMousePicker_setPickPtr
newCallback_RCISMousePicker_setPick(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_RCISMousePicker_setPick<T, CT>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 */
template<class T, typename CT> Callback_RCISMousePicker_setPickPtr
newCallback_RCISMousePicker_setPick(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_RCISMousePicker_setPick<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompRCISMousePicker::RCISMousePicker::begin_setPick.
 */
template<class T, typename CT> Callback_RCISMousePicker_setPickPtr
newCallback_RCISMousePicker_setPick(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_RCISMousePicker_setPick<T, CT>(instance, 0, excb, sentcb);
}

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
