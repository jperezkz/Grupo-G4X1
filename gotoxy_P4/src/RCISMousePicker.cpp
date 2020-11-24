//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.3
//
// <auto-generated>
//
// Generated from file `RCISMousePicker.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <RCISMousePicker.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ValueFactory.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/InputStream.h>
#include <Ice/OutputStream.h>
#include <IceUtil/PopDisableWarnings.h>

#if defined(_MSC_VER)
#   pragma warning(disable:4458) // declaration of ... hides class member
#elif defined(__clang__)
#   pragma clang diagnostic ignored "-Wshadow"
#elif defined(__GNUC__)
#   pragma GCC diagnostic ignored "-Wshadow"
#endif

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 >= 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 3
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace
{

const ::std::string iceC_RoboCompRCISMousePicker_RCISMousePicker_ids[2] =
{
    "::Ice::Object",
    "::RoboCompRCISMousePicker::RCISMousePicker"
};
const ::std::string iceC_RoboCompRCISMousePicker_RCISMousePicker_ops[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "setPick"
};
const ::std::string iceC_RoboCompRCISMousePicker_RCISMousePicker_setPick_name = "setPick";

}

bool
RoboCompRCISMousePicker::RCISMousePicker::ice_isA(::std::string s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompRCISMousePicker_RCISMousePicker_ids, iceC_RoboCompRCISMousePicker_RCISMousePicker_ids + 2, s);
}

::std::vector<::std::string>
RoboCompRCISMousePicker::RCISMousePicker::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector<::std::string>(&iceC_RoboCompRCISMousePicker_RCISMousePicker_ids[0], &iceC_RoboCompRCISMousePicker_RCISMousePicker_ids[2]);
}

::std::string
RoboCompRCISMousePicker::RCISMousePicker::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompRCISMousePicker::RCISMousePicker::ice_staticId()
{
    static const ::std::string typeId = "::RoboCompRCISMousePicker::RCISMousePicker";
    return typeId;
}

/// \cond INTERNAL
bool
RoboCompRCISMousePicker::RCISMousePicker::_iceD_setPick(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    Pick iceP_myPick;
    istr->readAll(iceP_myPick);
    inS.endReadParams();
    this->setPick(::std::move(iceP_myPick), current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompRCISMousePicker::RCISMousePicker::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompRCISMousePicker_RCISMousePicker_ops, iceC_RoboCompRCISMousePicker_RCISMousePicker_ops + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompRCISMousePicker_RCISMousePicker_ops)
    {
        case 0:
        {
            return _iceD_ice_id(in, current);
        }
        case 1:
        {
            return _iceD_ice_ids(in, current);
        }
        case 2:
        {
            return _iceD_ice_isA(in, current);
        }
        case 3:
        {
            return _iceD_ice_ping(in, current);
        }
        case 4:
        {
            return _iceD_setPick(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond INTERNAL
void
RoboCompRCISMousePicker::RCISMousePickerPrx::_iceI_setPick(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const Pick& iceP_myPick, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompRCISMousePicker_RCISMousePicker_setPick_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_myPick);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
::std::shared_ptr<::Ice::ObjectPrx>
RoboCompRCISMousePicker::RCISMousePickerPrx::_newInstance() const
{
    return ::IceInternal::createProxy<RCISMousePickerPrx>();
}
/// \endcond

const ::std::string&
RoboCompRCISMousePicker::RCISMousePickerPrx::ice_staticId()
{
    return RCISMousePicker::ice_staticId();
}

namespace Ice
{
}

#else // C++98 mapping

namespace
{

const ::std::string iceC_RoboCompRCISMousePicker_RCISMousePicker_setPick_name = "setPick";

}

/// \cond INTERNAL
::IceProxy::Ice::Object* ::IceProxy::RoboCompRCISMousePicker::upCast(RCISMousePicker* p) { return p; }

void
::IceProxy::RoboCompRCISMousePicker::_readProxy(::Ice::InputStream* istr, ::IceInternal::ProxyHandle< RCISMousePicker>& v)
{
    ::Ice::ObjectPrx proxy;
    istr->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new RCISMousePicker;
        v->_copyFrom(proxy);
    }
}
/// \endcond

::Ice::AsyncResultPtr
IceProxy::RoboCompRCISMousePicker::RCISMousePicker::_iceI_begin_setPick(const ::RoboCompRCISMousePicker::Pick& iceP_myPick, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompRCISMousePicker_RCISMousePicker_setPick_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompRCISMousePicker_RCISMousePicker_setPick_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_myPick);
        result->endWriteParams();
        result->invoke(iceC_RoboCompRCISMousePicker_RCISMousePicker_setPick_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompRCISMousePicker::RCISMousePicker::end_setPick(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompRCISMousePicker_RCISMousePicker_setPick_name);
}

/// \cond INTERNAL
::IceProxy::Ice::Object*
IceProxy::RoboCompRCISMousePicker::RCISMousePicker::_newInstance() const
{
    return new RCISMousePicker;
}
/// \endcond

const ::std::string&
IceProxy::RoboCompRCISMousePicker::RCISMousePicker::ice_staticId()
{
    return ::RoboCompRCISMousePicker::RCISMousePicker::ice_staticId();
}

RoboCompRCISMousePicker::RCISMousePicker::~RCISMousePicker()
{
}

/// \cond INTERNAL
::Ice::Object* RoboCompRCISMousePicker::upCast(RCISMousePicker* p) { return p; }

/// \endcond

namespace
{
const ::std::string iceC_RoboCompRCISMousePicker_RCISMousePicker_ids[2] =
{
    "::Ice::Object",
    "::RoboCompRCISMousePicker::RCISMousePicker"
};

}

bool
RoboCompRCISMousePicker::RCISMousePicker::ice_isA(const ::std::string& s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompRCISMousePicker_RCISMousePicker_ids, iceC_RoboCompRCISMousePicker_RCISMousePicker_ids + 2, s);
}

::std::vector< ::std::string>
RoboCompRCISMousePicker::RCISMousePicker::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&iceC_RoboCompRCISMousePicker_RCISMousePicker_ids[0], &iceC_RoboCompRCISMousePicker_RCISMousePicker_ids[2]);
}

const ::std::string&
RoboCompRCISMousePicker::RCISMousePicker::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompRCISMousePicker::RCISMousePicker::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::RoboCompRCISMousePicker::RCISMousePicker";
    return typeId;
#else
    return iceC_RoboCompRCISMousePicker_RCISMousePicker_ids[1];
#endif
}

/// \cond INTERNAL
bool
RoboCompRCISMousePicker::RCISMousePicker::_iceD_setPick(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    Pick iceP_myPick;
    istr->read(iceP_myPick);
    inS.endReadParams();
    this->setPick(iceP_myPick, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

namespace
{
const ::std::string iceC_RoboCompRCISMousePicker_RCISMousePicker_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "setPick"
};

}

/// \cond INTERNAL
bool
RoboCompRCISMousePicker::RCISMousePicker::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompRCISMousePicker_RCISMousePicker_all, iceC_RoboCompRCISMousePicker_RCISMousePicker_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompRCISMousePicker_RCISMousePicker_all)
    {
        case 0:
        {
            return _iceD_ice_id(in, current);
        }
        case 1:
        {
            return _iceD_ice_ids(in, current);
        }
        case 2:
        {
            return _iceD_ice_isA(in, current);
        }
        case 3:
        {
            return _iceD_ice_ping(in, current);
        }
        case 4:
        {
            return _iceD_setPick(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond STREAM
void
RoboCompRCISMousePicker::RCISMousePicker::_iceWriteImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice(ice_staticId(), -1, true);
    ::Ice::StreamWriter< RCISMousePicker, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
RoboCompRCISMousePicker::RCISMousePicker::_iceReadImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    ::Ice::StreamReader< RCISMousePicker, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}
/// \endcond

/// \cond INTERNAL
void
RoboCompRCISMousePicker::_icePatchObjectPtr(RCISMousePickerPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = RCISMousePickerPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(RCISMousePicker::ice_staticId(), v);
    }
}
/// \endcond

namespace Ice
{
}

#endif
