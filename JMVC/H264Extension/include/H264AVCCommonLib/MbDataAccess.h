#if !defined(AFX_MBDATAACCESS_H__710205A4_CFE9_496D_A469_C47EC8D2FBD2__INCLUDED_)
#define AFX_MBDATAACCESS_H__710205A4_CFE9_496D_A469_C47EC8D2FBD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "H264AVCCommonLib/SliceHeader.h"
#include "H264AVCCommonLib/MbData.h"
#include "H264AVCCommonLib/Tables.h"

H264AVC_NAMESPACE_BEGIN


class H264AVCCOMMONLIB_API MbDataAccess
{
private:
    enum PredictionType
    {
        PRED_A,
        PRED_B,
        PRED_C,
        MEDIAN
    };

public:

    Void *operator new( size_t stAllocateBlock, Void* pv )
    {
        return ( NULL == pv ) ? (::operator new( stAllocateBlock )) : pv;
    }

    MbDataAccess( MbDataAccess& rcMbDataAccess, MbData& rcMbData ) :
    m_rcMbCurr(                     rcMbData ),
#ifdef   LF_INTERLACE
        m_rcMbComplementary(            rcMbDataAccess.m_rcMbComplementary ),
#endif //LF_INTERLACE
        m_rcMbLeft(                     rcMbDataAccess.m_rcMbLeft ),
        m_rcMbAbove(                    rcMbDataAccess.m_rcMbAbove ),
        m_rcMbAboveLeft(                rcMbDataAccess.m_rcMbAboveLeft ),
        m_rcMbAboveRight(               rcMbDataAccess.m_rcMbAboveRight ),
#ifdef   LF_INTERLACE
        m_rcMbAboveAbove(               rcMbDataAccess.m_rcMbAboveAbove ),
        m_rcMbAboveAboveLeft(           rcMbDataAccess.m_rcMbAboveAboveLeft ),
        m_rcMbAboveAboveRight(          rcMbDataAccess.m_rcMbAboveAboveRight ),
        m_rcMbBelowLeft(                rcMbDataAccess.m_rcMbBelowLeft ),
#endif //LF_INTERLACE
        m_rcMbUnavailable(              rcMbDataAccess.m_rcMbUnavailable ),
#ifdef   LF_INTERLACE
        m_rcMbColocatedTop(             rcMbDataAccess.m_rcMbColocatedTop ),
        m_rcMbColocatedBot(             rcMbDataAccess.m_rcMbColocatedBot ),
#else //!LF_INTERLACE
        m_rcMbColocated(                rcMbDataAccess.m_rcMbColocated ),
#endif //LF_INTERLACE
        m_rcSliceHeader(                rcMbDataAccess.m_rcSliceHeader ),
        m_rcDFP(                        rcMbDataAccess.m_rcDFP ),
        m_cMv3D_A(                      rcMbDataAccess.m_cMv3D_A ),
        m_cMv3D_B(                      rcMbDataAccess.m_cMv3D_B ),
        m_cMv3D_C(                      rcMbDataAccess.m_cMv3D_C ),
        m_uiAvailable(                  rcMbDataAccess.m_uiAvailable ),
        m_uiPosX(                       rcMbDataAccess.m_uiPosX ),
        m_uiPosY(                       rcMbDataAccess.m_uiPosY ),
#ifdef   LF_INTERLACE
        m_bTopMb(                       rcMbDataAccess.m_bTopMb ),
        m_bUseTopField(                 rcMbDataAccess.m_bUseTopField ),
        m_bColocatedField(              rcMbDataAccess.m_bColocatedField ),
        m_bIsTopRowMb(                  rcMbDataAccess.m_bIsTopRowMb ),
        m_bMbAff(                       rcMbDataAccess.m_bMbAff ),
#endif //LF_INTERLACE
        m_ucLastMbQp(                   rcMbDataAccess.m_ucLastMbQp ),
#ifdef   LF_INTERLACE
        m_eMbPicType(                   rcMbDataAccess.m_eMbPicType ),
#endif //LF_INTERLACE
        m_pcMbDataAccessBase(           rcMbDataAccess.m_pcMbDataAccessBase )
    {
        m_rcMbCurr.copyFrom( rcMbDataAccess.getMbData() );
#ifdef   LF_INTERLACE
        //--- set motion data connections ---
        getMbMotionData( LIST_0 ).setFieldMode( rcMbDataAccess.getMbMotionData( LIST_0 ).getFieldMode() );
        getMbMotionData( LIST_1 ).setFieldMode( rcMbDataAccess.getMbMotionData( LIST_1 ).getFieldMode() );
#endif //LF_INTERLACE
    }


    MbDataAccess( MbData&          rcMbCurr,
#ifdef   LF_INTERLACE
        MbData&          rcMbComplementary,
#endif //LF_INTERLACE
        const MbData&    rcMbLeft,
        const MbData&    rcMbAbove,
        const MbData&    rcMbAboveLeft,
        const MbData&    rcMbAboveRight,
#ifdef   LF_INTERLACE
        const MbData&    rcMbAboveAbove,
        const MbData&    rcMbAboveAboveLeft,
        const MbData&    rcMbAboveAboveRight,
        const MbData&    rcMbBelowLeft,
#endif //LF_INTERLACE
        const MbData&    rcMbUnavailable,
#ifdef   LF_INTERLACE
        const MbData&    m_rcMbColocatedTop,
        const MbData&    m_rcMbColocatedBot,
#else //!LF_INTERLACE
        const MbData&    rcMbColocated,
#endif //LF_INTERLACE
        SliceHeader&     rcSliceHeader,
        const DFP&       rcDFP,
        UInt             uiPosX,
        UInt             uiPosY,
#ifdef   LF_INTERLACE
        Bool             bTopMb,
        Bool             bUseTopField,
        Bool             bColocatedField,
#endif //LF_INTERLACE
        SChar            ucLastMbQp )
        : m_rcMbCurr                    ( rcMbCurr                ),
#ifdef   LF_INTERLACE
        m_rcMbComplementary           ( rcMbComplementary       ),
#endif //LF_INTERLACE
        m_rcMbLeft                    ( rcMbLeft                ),
        m_rcMbAbove                   ( rcMbAbove               ),
        m_rcMbAboveLeft               ( rcMbAboveLeft           ),
        m_rcMbAboveRight              ( rcMbAboveRight          ),
#ifdef   LF_INTERLACE
        m_rcMbAboveAbove              ( rcMbAboveAbove          ),
        m_rcMbAboveAboveLeft          ( rcMbAboveAboveLeft      ),
        m_rcMbAboveAboveRight         ( rcMbAboveAboveRight     ),
        m_rcMbBelowLeft               ( rcMbBelowLeft           ),
#endif //LF_INTERLACE
        m_rcMbUnavailable             ( rcMbUnavailable         ),
#ifdef   LF_INTERLACE
        m_rcMbColocatedTop            ( m_rcMbColocatedTop      ),
        m_rcMbColocatedBot            ( m_rcMbColocatedBot      ),
#else //!LF_INTERLACE
        m_rcMbColocated               ( rcMbColocated         ),
#endif //LF_INTERLACE
        m_rcSliceHeader               ( rcSliceHeader           ),
        m_rcDFP                       ( rcDFP                   ),
        m_cMv3D_A                     ( 0, 0, 0                 ),
        m_cMv3D_B                     ( 0, 0, 0                 ),
        m_cMv3D_C                     ( 0, 0, 0                 ),
        m_uiAvailable                 ( 0                       ),
        m_uiPosX                      ( uiPosX                  ),
        m_uiPosY                      ( uiPosY                  ),
#ifdef   LF_INTERLACE
        m_bTopMb                      ( bTopMb                  ),
        m_bUseTopField                ( bUseTopField            ),
        m_bColocatedField             ( bColocatedField         ),
        m_bMbAff                      ( rcSliceHeader.isMbAff() ),
#endif //LF_INTERLACE
        m_ucLastMbQp                  ( ucLastMbQp              ),
        m_pcMbDataAccessBase          ( NULL                    )
    {
#ifdef   LF_INTERLACE
        m_bIsTopRowMb = ( m_rcSliceHeader.getFieldPicFlag() ? ! m_rcSliceHeader.getBottomFieldFlag() : ( m_uiPosY % 2 == 0 ) );
        m_eMbPicType  = ( m_rcSliceHeader.getFieldPicFlag()
            ? ( m_rcSliceHeader.getBottomFieldFlag()   ? BOT_FIELD : TOP_FIELD )
            : ( m_rcMbCurr.getFieldFlag() ? ( m_bTopMb ? TOP_FIELD : BOT_FIELD ) : FRAME ) );
#endif //LF_INTERLACE
        setAvailableMask();
    }


    ~MbDataAccess()
    {
    }


public:

    const MbData&   getMbData             ()    const { return m_rcMbCurr; }
    MbData&         getMbData             ()          { return m_rcMbCurr; }
    const MbData&   getMbDataCurr         ()    const { return m_rcMbCurr; }
    const MbData&   getMbDataLeft         ()    const { return m_rcMbLeft; }
    const MbData&   getMbDataAbove        ()    const { return m_rcMbAbove; }
    const MbData&   getMbDataAboveLeft    ()    const { return m_rcMbAboveLeft; }
#ifdef   LF_INTERLACE
    const MbData&   getMbDataAboveAbove   ()    const { return m_rcMbAboveAbove; }
    const MbData&   getMbDataBelowLeft    ()    const { return m_rcMbBelowLeft; }
#endif
#ifdef   LF_INTERLACE
    const MbData&   getMbDataComplementary()    const { return m_rcMbComplementary; }
    Bool            isTopMb               ()    const { return m_bTopMb; }
    PicType         getMbPicType          ()    const { return m_eMbPicType; }
    Bool            isFieldMbInMbaffFrame ()    const { return ( m_bMbAff ) && ( getMbPicType() != FRAME ); }
    Void            setFieldMode          ( Bool bFieldFlag )
    {
        AOF_DBG( m_bMbAff );
        //----- set field flag in MbDataStruct -----
        m_rcMbCurr         .setFieldFlag( bFieldFlag );
        m_rcMbComplementary.setFieldFlag( bFieldFlag );
        //----- set field mode in MbMotionData -----
        m_rcMbCurr         .getMbMotionData( LIST_0 ).setFieldMode( bFieldFlag );
        m_rcMbCurr         .getMbMotionData( LIST_1 ).setFieldMode( bFieldFlag );
        m_rcMbComplementary.getMbMotionData( LIST_0 ).setFieldMode( bFieldFlag );
        m_rcMbComplementary.getMbMotionData( LIST_1 ).setFieldMode( bFieldFlag );
        //----- set MbPicType -----
        m_eMbPicType = ( m_rcSliceHeader.getFieldPicFlag()
            ? ( m_rcSliceHeader.getBottomFieldFlag() ? BOT_FIELD : TOP_FIELD )
            : ( bFieldFlag ? ( isTopMb() ? TOP_FIELD : BOT_FIELD ) : FRAME ) );
		setAvailableMask();
    }
#endif //LF_INTERLACE

    UInt      getNumActiveRef       ( ListIdx eListIdx) const
    {
#ifdef LF_INTERLACE
        if( m_rcSliceHeader.getPicType() == FRAME && FRAME != getMbPicType() )
        {
            return m_rcSliceHeader.getNumRefIdxActive( eListIdx ) * 2;
        }
#endif
        return m_rcSliceHeader.getNumRefIdxActive( eListIdx );
    }

#ifdef   LF_INTERLACE
    Bool getDefaultFieldFlag() const
    {
        if( xIsAvailable( m_rcMbLeft ) )
        {
            return m_rcMbLeft.getFieldFlag();
        }
        if( xIsAvailable( m_rcMbAboveAbove ) )
        {
            return m_rcMbAboveAbove.getFieldFlag();
        }
        return false;
    }
#endif //LF_INTERLACE
    UInt    getConvertBlkMode ( Par8x8 ePar8x8 );
    ErrVal  setConvertBlkMode ( Par8x8 ePar8x8, UInt uiBlockMode );
    UInt    getConvertMbType  ();
    ErrVal  setConvertMbType  ( UInt uiMbType );
    Bool    isSkippedMb       ()                    const
    {
        ROTRS( m_rcSliceHeader.isIntra(), false );
        if( m_rcSliceHeader.isInterB() )
        {
            return (m_rcMbCurr.getMbMode() == MODE_SKIP) &&
                (m_rcMbCurr.getMbCbp () == 0)         &&
                !(m_rcMbCurr.getResidualPredFlag(PART_16x16));
        }
    return 
		m_rcMbCurr.getMbMode() == MODE_SKIP;
    }

    Void    setLastQp   ( Int iQp  )  { m_ucLastMbQp = (UChar)iQp; }

    Void    addDeltaQp  ( Int iDQp )              { m_rcMbCurr.setQp( (m_ucLastMbQp + iDQp+(MAX_QP+1)) % (MAX_QP+1) ); }
    Void    resetQp     ()                        { m_rcMbCurr.setQp( m_ucLastMbQp );  }
    Int     getDeltaQp  ()                        { return (m_rcMbCurr.getQp() - m_ucLastMbQp); }
    UChar   getLastQp  ()                   const { return m_ucLastMbQp; }


    const SliceHeader&       getSH           ()                    const { return m_rcSliceHeader;}
    SliceHeader&             getSH           ()                          { return m_rcSliceHeader;}
    const MbTransformCoeffs& getMbTCoeffs    ()                    const { return m_rcMbCurr.getMbTCoeffs    (); }
    const MbMvData&          getMbMvdData    ( ListIdx eListIdx )  const { return m_rcMbCurr.getMbMvdData    ( eListIdx ); }
    const MbMotionData&      getMbMotionData ( ListIdx eListIdx )  const { return m_rcMbCurr.getMbMotionData ( eListIdx ); }
    MbTransformCoeffs&       getMbTCoeffs    ()                          { return m_rcMbCurr.getMbTCoeffs    (); }
    MbMvData&                getMbMvdData    ( ListIdx eListIdx )        { return m_rcMbCurr.getMbMvdData    ( eListIdx ); }
    MbMotionData&            getMbMotionData ( ListIdx eListIdx )        { return m_rcMbCurr.getMbMotionData ( eListIdx ); }

    Int   mostProbableIntraPredMode ( LumaIdx cIdx );
    Int   encodeIntraPredMode       ( LumaIdx cIdx );
    Int   decodeIntraPredMode       ( LumaIdx cIdx );

    UInt  getAvailableMask  () const { return m_uiAvailable; }
    Bool  isAvailableLeft   () const { return xIsAvailable( m_rcMbLeft  ); }
    Bool  isAvailableAbove  () const { B4x4Idx cIdx; return xIsAvailable( xGetBlockAbove( cIdx ) ); }

    Bool  isLeftMbExisting        () const { return m_uiPosX != 0; }

#ifdef LF_INTERLACE
    Bool  isAboveMbExisting       () const { return ( ! ((m_uiPosY == 0) || ((m_uiPosY == 1) && m_rcMbCurr.getFieldFlag()))); }
#else
    Bool  isAboveMbExisting () const { return ( ! ( m_uiPosY == 0 ) ); }
#endif //LF_INTERLACE

  Bool isConstrainedInterLayerPred( )
    {
#if MULTIPLE_LOOP_DECODING
        if( getSH().getSPS().getAlwaysDecodeBaseLayer() )
        {
            return false;
        }
        else
#endif
            return getSH().getBaseLayerUsesConstrainedIntraPred();
    }

    UInt getCtxChromaPredMode ()                  const;
    UInt getCtxCoeffCount     ( LumaIdx cIdx )    const;
    UInt getCtxCoeffCount     ( ChromaIdx cIdx )  const;
    UInt getCtxMbSkipped      ()                  const;
    UInt getCtxBLSkipFlag     ()                  const;
    UInt getCtxDirectMbWoCoeff()                  const;
    UInt getCtxCodedBlockBit  ( UInt uiBitPos )   const;
#ifdef   LF_INTERLACE
    UInt getCtxFieldFlag      ()                  const;
#endif //LF_INTERLACE
    UInt getCtxRefIdx         ( ListIdx eLstIdx, ParIdx8x8 eParIdx ) const;
    UInt getCtxMotPredFlag    ( ListIdx eLstIdx, ParIdx8x8 eParIdx ) const;
    UInt getCtxBLQRefFlag     ()                  const;
    UInt getCtxMbIntra4x4     ()                  const;
    UInt getCtxMbType         ()                  const;
    UInt getCtx8x8Flag        ()                  const;

    UInt  getLeftLumaCbp          ( LumaIdx cIdx )  const;
    UInt  getAboveLumaCbp         ( LumaIdx cIdx )  const;
    UInt  getLeftChromaCbp        ()                const;
    UInt  getAboveChromaCbp       ()                const;
    UInt  getAutoCbp              ()                const;

    UInt  getLeftLumaCbpFGS       ( LumaIdx cIdx )  const;
    UInt  getAboveLumaCbpFGS      ( LumaIdx cIdx )  const;
    UInt  getLeftChromaCbpFGS     ()                const;
    UInt  getAboveChromaCbpFGS    ()                const;

    Void  getMvdLeft    ( Mv& rcMv, ListIdx eListIdx, LumaIdx cIdx )  const;
    Void  getMvdAbove   ( Mv& rcMv, ListIdx eListIdx, LumaIdx cIdx )  const;

    Void  getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx );
    Void  getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx16x8 eParIdx );
    Void  getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x16 eParIdx );
    Void  getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x8  eParIdx );
    Void  getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x8  eParIdx, SParIdx8x4 eSParIdx );
    Void  getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x8  eParIdx, SParIdx4x8 eSParIdx );
    Void  getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x8  eParIdx, SParIdx4x4 eSParIdx );
#ifdef LF_INTERLACE
    Void  getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx16x16 eParIdx );
    Void  getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x8  eParIdx, SParIdx8x8 eSParIdx );
#endif



    Void  setMvPredictorsBL( const Mv& rcMvBL, ListIdx eListIdx );
    Void  setMvPredictorsBL( const Mv& rcMvBL, ListIdx eListIdx, ParIdx16x8 eParIdx );
    Void  setMvPredictorsBL( const Mv& rcMvBL, ListIdx eListIdx, ParIdx8x16 eParIdx );
    Void  setMvPredictorsBL( const Mv& rcMvBL, ListIdx eListIdx, ParIdx8x8  eParIdx );
    Void  setMvPredictorsBL( const Mv& rcMvBL, ListIdx eListIdx, ParIdx8x8  eParIdx, SParIdx8x4 eSParIdx );
    Void  setMvPredictorsBL( const Mv& rcMvBL, ListIdx eListIdx, ParIdx8x8  eParIdx, SParIdx4x8 eSParIdx );
    Void  setMvPredictorsBL( const Mv& rcMvBL, ListIdx eListIdx, ParIdx8x8  eParIdx, SParIdx4x4 eSParIdx );
#ifdef LF_INTERLACE
    Void  setMvPredictorsBL( const Mv& rcMvBL, ListIdx eListIdx, ParIdx16x16 eParIdx );
    Void  setMvPredictorsBL( const Mv& rcMvBL, ListIdx eListIdx, ParIdx8x8  eParIdx, SParIdx8x8 eSParIdx );
#endif


    Void  getMvPredictors       ( Mv* pcMv     ) const;
    Void  getMvPredictorSkipMode();
    Void  getMvPredictorSkipMode( Mv& cMvPred  );
    Bool  getMvPredictorDirect  ( ParIdx8x8 eParIdx, Bool& rbOneMv, Bool bFaultTolerant );
//	TMM_EC {{
    Bool  getMvPredictorDirectVirtual ( ParIdx8x8 eParIdx, Bool& rbOneMv, Bool bFaultTolerant, RefFrameList& rcRefFrameListL0, RefFrameList& rcRefFrameListL1  );
//  TMM_EC }}

    const DFP& getDeblockingFilterParameter()     const { return m_rcDFP; }

    Void getMvSkipMode( Mv& rcMv )
    {
        xGetMvPredictor( rcMv, 1, LIST_0, MEDIAN, B4x4Idx(0), B4x4Idx(3) );

        if( ( m_cMv3D_A.getRef()==BLOCK_NOT_AVAILABLE ||
            m_cMv3D_B.getRef()==BLOCK_NOT_AVAILABLE      ) ||
            ( m_cMv3D_A.getHor()==0 && m_cMv3D_A.getVer()==0 && m_cMv3D_A.getRef()==1 ) ||
            ( m_cMv3D_B.getHor()==0 && m_cMv3D_B.getVer()==0 && m_cMv3D_B.getRef()==1 )   )
        {
            rcMv.setZero();
        }
    }


    MbDataAccess* getMbDataAccessBase() const { return m_pcMbDataAccessBase; }
    Void          setMbDataAccessBase( MbDataAccess* p ) { m_pcMbDataAccessBase = p; }

    UInt  getMbX() const { return m_uiPosX; }
    UInt  getMbY() const { return m_uiPosY; }

	Void  setAvailableMask ();

protected:
    Void  xSetMvPredictorsBL          ( const Mv& rcMvPredBL, ListIdx eListIdx, LumaIdx cIdx, LumaIdx cIdxEnd );

    Void  xGetMvPredictor             ( Mv& rcMvPred, SChar scRef, ListIdx eListIdx, PredictionType ePredType, LumaIdx cIdx, LumaIdx cIdxEnd );
    Void  xSetNeighboursMvPredictor   ( ListIdx eListIdx, LumaIdx cIdx, LumaIdx cIdxEnd );
    Void  xGetMvPredictorUseNeighbours( Mv& rcMvPred, SChar scRef, PredictionType ePredType );

    __inline const MbData& xGetMbLeft           () const;
    __inline const MbData& xGetMbAbove          () const;
    __inline const MbData& xGetBlockLeft        ( LumaIdx&   rcIdx ) const;
#ifdef   LF_INTERLACE
    __inline const MbData& xGetBlockLeftBottom  ( LumaIdx&   rcIdx ) const;
#endif //LF_INTERLACE
    __inline const MbData& xGetBlockAbove       ( LumaIdx&   rcIdx ) const;
    __inline const MbData& xGetBlockAboveLeft   ( LumaIdx&   cIdx ) const;
    __inline const MbData& xGetBlockAboveRight  ( LumaIdx&   cIdx ) const;

    __inline UInt  xGetLeftCodedBlockBit    ( UInt uiBit   )  const;
    __inline UInt  xGetAboveCodedBlockBit   ( UInt uiBit   )  const;
    __inline SChar xGetRefIdxLeft ( ListIdx eListIdx, ParIdx8x8 eParIdx )       const;
    __inline SChar xGetRefIdxAbove( ListIdx eListIdx, ParIdx8x8 eParIdx )       const;

#ifdef   LF_INTERLACE
    enum MvRefConversion
    {
        ONE_TO_ONE,
        FRM_TO_FLD,
        FLD_TO_FRM
    };
    __inline const MbData& xGetBlockColocated                 ( LumaIdx&  rcIdx, MvRefConversion& eMvRefConversion )  const;
    __inline const MbData& xGetBlockColocatedNonInterlaced    () const;
#endif //LF_INTERLACE

    __inline Bool xGetMotPredFlagLeft ( ListIdx eListIdx, ParIdx8x8 eParIdx )       const;
    __inline Bool xGetMotPredFlagAbove( ListIdx eListIdx, ParIdx8x8 eParIdx )       const;

    __inline Void          xGetColocatedMvRefIdx              ( Mv& rcMv, SChar& rscRefIdx, LumaIdx cIdx ) const;
    __inline const RefPic& xGetColocatedMvRefPic              ( Mv& rcMv, SChar& rscRefIdx, LumaIdx cIdx ) const;

    __inline Void          xGetColocatedMvsRefIdxNonInterlaced( Mv acMv[], SChar& rscRefIdx, ParIdx8x8 eParIdx ) const;
    __inline const RefPic& xGetColocatedMvsRefPicNonInterlaced( Mv acMv[], SChar& rscRefIdx, ParIdx8x8 eParIdx ) const;

    Void xSpatialDirectMode ( ParIdx8x8 eParIdx, Bool b8x8 );
    Bool xTemporalDirectMode( ParIdx8x8 eParIdx, Bool b8x8, Bool bFaultTolerant );
    Bool xTemporalDirectModeMvRef( Mv acMv[], SChar ascRefIdx[], LumaIdx cIdx, Bool bFaultTolerant );
    Bool xTemporalDirectModeMvsRefNonInterlaced( Mv aacMv[][4], SChar ascRefIdx[], ParIdx8x8 eParIdx, Bool bFaultTolerant );
//	TMM_EC {{
    Bool xTemporalDirectModeVirtual( ParIdx8x8 eParIdx, Bool b8x8, Bool bFaultTolerant, RefFrameList& rcRefFrameListL0, RefFrameList& rcRefFrameListL1 );
    Bool xTemporalDirectModeMvRefVirtual( Mv acMv[], SChar ascRefIdx[], LumaIdx cIdx, Bool bFaultTolerant, RefFrameList& rcRefFrameListL0, RefFrameList& rcRefFrameListL1);
//  TMM_EC }}

    Bool  xIsAvailable     ( const MbData& rcMbData )  const
    {
        return   ( rcMbData.getSliceId() == m_rcMbCurr.getSliceId() );
    }
    Bool  xIsAvailableIntra( const MbData& rcMbData )  const
    {
        Bool  bConstrainedIntraPred = m_rcSliceHeader.getPPS().getConstrainedIntraPredFlag();
        return ( xIsAvailable( rcMbData ) && ( rcMbData.isIntra() || ! bConstrainedIntraPred ) );
    }
#ifdef   LF_INTERLACE_FIX
    __inline Bool xCheckMv (const Mv& rcMv) const
    { 
        UInt uiLevel = getSH().getSPS().getLevelIdc();
        Int  iMaxVerMv = getSH().getSPS().getMaxIntMvVer(uiLevel, getSH().getFieldPicFlag() || m_rcMbCurr.getFieldFlag());
        Int  iMaxHorMv = getSH().getSPS().getMaxIntMvHor();
      
  return ((rcMv.getHor() >= (-iMaxHorMv)) && (rcMv.getHor() < iMaxHorMv) && (rcMv.getVer() >= (-iMaxVerMv)) && (rcMv.getVer() < iMaxVerMv));
    } 
#endif //LF_INTERLACE_FIX
private:
    static const BlkMode m_aucBMTabB0[13];
    static const UChar   m_aucBMTabB1[13];
    static const BlkMode m_aucBMTabP[4];
    static const MbMode  m_aausInterBMbType0[23];
    static const UShort  m_aausInterBMbType1[23];
    static const UChar   m_aucMbType1x2[9];
    static const UChar   m_aucMbType2x1[9];
    static const UChar   m_aucChroma2LumaIdx[8];
    static const UChar   m_auc4x4Idx28x8Idx[16];

public:
    MbData&        m_rcMbCurr;
#ifdef   LF_INTERLACE
    MbData&        m_rcMbComplementary;
#endif //LF_INTERLACE
    const MbData&  m_rcMbLeft;
    const MbData&  m_rcMbAbove;
    const MbData&  m_rcMbAboveLeft;
    const MbData&  m_rcMbAboveRight;
#ifdef   LF_INTERLACE
    const MbData&  m_rcMbAboveAbove;
    const MbData&  m_rcMbAboveAboveLeft;
    const MbData&  m_rcMbAboveAboveRight;
    const MbData&  m_rcMbBelowLeft;
#endif //LF_INTERLACE
    const MbData&  m_rcMbUnavailable;
#ifdef   LF_INTERLACE
    const MbData&  m_rcMbColocatedTop;
    const MbData&  m_rcMbColocatedBot;
#else //!LF_INTERLACE
    const MbData&  m_rcMbColocated;
#endif //LF_INTERLACE

    SliceHeader&  m_rcSliceHeader;
    const DFP&          m_rcDFP;

    Mv3D  m_cMv3D_A;
    Mv3D  m_cMv3D_B;
    Mv3D  m_cMv3D_C;

    UInt      m_uiAvailable;
    UInt      m_uiPosX;
    UInt      m_uiPosY;
#ifdef   LF_INTERLACE
    Bool      m_bTopMb;
    Bool      m_bUseTopField;
    Bool      m_bColocatedField;
    Bool      m_bIsTopRowMb;
    Bool      m_bMbAff;
#endif //LF_INTERLACE
    SChar     m_ucLastMbQp;
#ifdef LF_INTERLACE
    PicType   m_eMbPicType;
#endif //LF_INTERLACE

    MbDataAccess* m_pcMbDataAccessBase;
};

#ifdef LF_INTERLACE
__inline Void MbDataAccess::getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx16x16 eParIdx )
{
    xGetMvPredictor( rcMv, scRef, eListIdx, MEDIAN, B4x4Idx( 0 ), B4x4Idx( 3 ) );
}
__inline Void MbDataAccess::getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x8  eParIdx, SParIdx8x8 eSParIdx )
{
    xGetMvPredictor( rcMv, scRef, eListIdx, MEDIAN, B4x4Idx( eParIdx ), B4x4Idx( eParIdx+1 ) );
}
#endif
__inline Void MbDataAccess::getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx )
{
    xGetMvPredictor( rcMv, scRef, eListIdx, MEDIAN, B4x4Idx( 0 ), B4x4Idx( 3 ) );
}
__inline Void MbDataAccess::getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx16x8 eParIdx )
{
    PredictionType ePred = ( eParIdx == PART_16x8_0 ? PRED_B : PRED_A );
    xGetMvPredictor( rcMv, scRef, eListIdx, ePred, B4x4Idx( eParIdx ), B4x4Idx( eParIdx+3 ) );
}
__inline Void MbDataAccess::getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x16 eParIdx )
{
    PredictionType ePred = ( eParIdx == PART_8x16_0 ? PRED_A : PRED_C );
    xGetMvPredictor( rcMv, scRef, eListIdx, ePred, B4x4Idx( eParIdx ), B4x4Idx( eParIdx+1 ) );
}
__inline Void MbDataAccess::getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x8 eParIdx )
{
    xGetMvPredictor( rcMv, scRef, eListIdx, MEDIAN, B4x4Idx( eParIdx ), B4x4Idx( eParIdx+1 ) );
}
__inline Void MbDataAccess::getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x8 eParIdx, SParIdx8x4 eSParIdx )
{
    xGetMvPredictor( rcMv, scRef, eListIdx, MEDIAN, B4x4Idx( eParIdx+eSParIdx ), B4x4Idx( eParIdx+eSParIdx+1 ) );
}
__inline Void MbDataAccess::getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x8 eParIdx, SParIdx4x8 eSParIdx )
{
    xGetMvPredictor( rcMv, scRef, eListIdx, MEDIAN, B4x4Idx( eParIdx+eSParIdx ), B4x4Idx( eParIdx+eSParIdx ) );
}
__inline Void MbDataAccess::getMvPredictor( Mv& rcMv, SChar scRef, ListIdx eListIdx, ParIdx8x8 eParIdx, SParIdx4x4 eSParIdx )
{
    xGetMvPredictor( rcMv, scRef, eListIdx, MEDIAN, B4x4Idx( eParIdx+eSParIdx ), B4x4Idx( eParIdx+eSParIdx ) );
}




#ifdef LF_INTERLACE
__inline Void MbDataAccess::setMvPredictorsBL( const Mv& rcMv, ListIdx eListIdx, ParIdx16x16 eParIdx )
{
    xSetMvPredictorsBL( rcMv, eListIdx, B4x4Idx( 0 ), B4x4Idx( 3 ) );
}
__inline Void MbDataAccess::setMvPredictorsBL( const Mv& rcMv, ListIdx eListIdx, ParIdx8x8  eParIdx, SParIdx8x8 eSParIdx )
{
    xSetMvPredictorsBL( rcMv, eListIdx, B4x4Idx( eParIdx ), B4x4Idx( eParIdx+1 ) );
}
#endif
__inline Void MbDataAccess::setMvPredictorsBL( const Mv& rcMv, ListIdx eListIdx )
{
    xSetMvPredictorsBL( rcMv, eListIdx, B4x4Idx( 0 ), B4x4Idx( 3 ) );
}
__inline Void MbDataAccess::setMvPredictorsBL( const Mv& rcMv, ListIdx eListIdx, ParIdx16x8 eParIdx )
{
    xSetMvPredictorsBL( rcMv, eListIdx, B4x4Idx( eParIdx ), B4x4Idx( eParIdx+3 ) );
}
__inline Void MbDataAccess::setMvPredictorsBL( const Mv& rcMv, ListIdx eListIdx, ParIdx8x16 eParIdx )
{
    xSetMvPredictorsBL( rcMv, eListIdx, B4x4Idx( eParIdx ), B4x4Idx( eParIdx+1 ) );
}
__inline Void MbDataAccess::setMvPredictorsBL( const Mv& rcMv, ListIdx eListIdx, ParIdx8x8 eParIdx )
{
    xSetMvPredictorsBL( rcMv, eListIdx, B4x4Idx( eParIdx ), B4x4Idx( eParIdx+1 ) );
}
__inline Void MbDataAccess::setMvPredictorsBL( const Mv& rcMv, ListIdx eListIdx, ParIdx8x8 eParIdx, SParIdx8x4 eSParIdx )
{
    xSetMvPredictorsBL( rcMv, eListIdx, B4x4Idx( eParIdx+eSParIdx ), B4x4Idx( eParIdx+eSParIdx+1 ) );
}
__inline Void MbDataAccess::setMvPredictorsBL( const Mv& rcMv, ListIdx eListIdx, ParIdx8x8 eParIdx, SParIdx4x8 eSParIdx )
{
    xSetMvPredictorsBL( rcMv, eListIdx, B4x4Idx( eParIdx+eSParIdx ), B4x4Idx( eParIdx+eSParIdx ) );
}
__inline Void MbDataAccess::setMvPredictorsBL( const Mv& rcMv, ListIdx eListIdx, ParIdx8x8 eParIdx, SParIdx4x4 eSParIdx )
{
    xSetMvPredictorsBL( rcMv, eListIdx, B4x4Idx( eParIdx+eSParIdx ), B4x4Idx( eParIdx+eSParIdx ) );
}




__inline SChar MbDataAccess::xGetRefIdxLeft( ListIdx eListIdx, ParIdx8x8 eParIdx ) const
{
    B4x4Idx       cIdx( eParIdx );
    const MbData& rcMbData  = xGetBlockLeft( cIdx );
    if( 
        rcMbData.getBLSkipFlag() || rcMbData.getMbMotionData( eListIdx ).getMotPredFlag( ParIdx8x8( cIdx.b4x4() ) ) )
    {
        return BLOCK_NOT_AVAILABLE;
    }

    if( m_rcSliceHeader.isInterB() )
    {
        if( rcMbData.getMbMode() == MODE_SKIP || ( rcMbData.getMbMode() == MODE_8x8 && rcMbData.getBlkMode( Par8x8( 2*(cIdx.y()/2) + cIdx.x()/2 ) ) == BLK_SKIP ) )
            return BLOCK_NOT_AVAILABLE;
    }

    SChar  scRefIdx  = rcMbData.getMbMotionData( eListIdx ).getRefIdx( ParIdx8x8( cIdx.b4x4() ) );
#ifdef   LF_INTERLACE
    if( scRefIdx > BLOCK_NOT_AVAILABLE )
    {
        if( rcMbData.getFieldFlag() && ! m_rcMbCurr.getFieldFlag() )
        {
            scRefIdx = ((scRefIdx-1)>>1)+1;//th fix
            //      scRefIdx >>= 1; 
        }
        else if( ! rcMbData.getFieldFlag() && m_rcMbCurr.getFieldFlag() )
        {
            scRefIdx = ((scRefIdx-1)<<1)+1;//th fix
            //      scRefIdx <<= 1; 
        }
    }
#endif //LF_INTERLACE
    return scRefIdx;
}

__inline SChar MbDataAccess::xGetRefIdxAbove( ListIdx eListIdx, ParIdx8x8 eParIdx ) const
{
    B4x4Idx       cIdx( eParIdx );
    const MbData& rcMbData  = xGetBlockAbove( cIdx );

    if( 
        rcMbData.getBLSkipFlag() || rcMbData.getMbMotionData( eListIdx ).getMotPredFlag( ParIdx8x8( cIdx.b4x4() ) ) )
    {
        return BLOCK_NOT_AVAILABLE;
    }

    if( m_rcSliceHeader.isInterB() )
    {
        if( rcMbData.getMbMode() == MODE_SKIP || ( rcMbData.getMbMode() == MODE_8x8 && rcMbData.getBlkMode( Par8x8( 2*(cIdx.y()/2) + cIdx.x()/2 ) ) == BLK_SKIP ) )
            return BLOCK_NOT_AVAILABLE;
    }

    SChar  scRefIdx  = rcMbData.getMbMotionData( eListIdx ).getRefIdx( ParIdx8x8( cIdx.b4x4() ) );

#ifdef   LF_INTERLACE
    if( scRefIdx > BLOCK_NOT_AVAILABLE )
    {
        if( rcMbData.getFieldFlag() && ! m_rcMbCurr.getFieldFlag() )
        {
            scRefIdx = ((scRefIdx-1)>>1)+1;//th fix
            //      scRefIdx >>= 1;
        }
        else if( ! rcMbData.getFieldFlag() && m_rcMbCurr.getFieldFlag() )
        {
            scRefIdx = ((scRefIdx-1)<<1)+1;//th fix
            //      scRefIdx <<= 1;
        }
    }
#endif //LF_INTERLACE

    return scRefIdx;
}



__inline Bool MbDataAccess::xGetMotPredFlagLeft( ListIdx eListIdx, ParIdx8x8 eParIdx ) const
{
    B4x4Idx       cIdx( eParIdx );
    const MbData& rcMbData  = xGetBlockLeft( cIdx );

    Bool  bFlag  = rcMbData.getMbMotionData( eListIdx ).getMotPredFlag( ParIdx8x8( cIdx.b4x4() ) );

    return bFlag;
}


__inline Bool MbDataAccess::xGetMotPredFlagAbove( ListIdx eListIdx, ParIdx8x8 eParIdx ) const
{
    B4x4Idx       cIdx( eParIdx );
    const MbData& rcMbData  = xGetBlockAbove( cIdx );

    Bool  bFlag  = rcMbData.getMbMotionData( eListIdx ).getMotPredFlag( ParIdx8x8( cIdx.b4x4() ) );

    return bFlag;
}



__inline Void MbDataAccess::getMvdLeft( Mv& rcMv, ListIdx eListIdx, LumaIdx cIdx ) const
{
    const MbData& rcMbData = xGetBlockLeft( cIdx );
    rcMv = rcMbData.getMbMvdData( eListIdx ).getMv( cIdx );
#ifdef   LF_INTERLACE
    if( rcMbData.getFieldFlag() && ! m_rcMbCurr.getFieldFlag() )
    {
        rcMv.setVer( rcMv.getVer() * 2 );
    }
    else if( ! rcMbData.getFieldFlag() && m_rcMbCurr.getFieldFlag() )
    {
        rcMv.setVer( rcMv.getVer() / 2 );
    }
#endif //LF_INTERLACE
}

__inline Void MbDataAccess::getMvdAbove( Mv& rcMv, ListIdx eListIdx, LumaIdx cIdx ) const
{
    const MbData& rcMbData = xGetBlockAbove( cIdx );
    rcMv = rcMbData.getMbMvdData( eListIdx ).getMv( cIdx );
#ifdef   LF_INTERLACE
    if( rcMbData.getFieldFlag() && ! m_rcMbCurr.getFieldFlag() )
    {
        rcMv.setVer( rcMv.getVer() * 2 );
    }
    else if( ! rcMbData.getFieldFlag() && m_rcMbCurr.getFieldFlag() )
    {
        rcMv.setVer( rcMv.getVer() / 2 );
    }
#endif //LF_INTERLACE
}




__inline UInt MbDataAccess::getCtxCoeffCount( LumaIdx cIdx )  const
{
    Bool bLeftAvailable = false;
    UInt uiCoeffCount   = 0;

    {
        B4x4Idx cIdxL( cIdx.b4x4() );
        const MbData& rcMbDataLeft = xGetBlockLeft( cIdxL );

        if( xIsAvailable( rcMbDataLeft ) )
        {
            bLeftAvailable = true;
            uiCoeffCount = rcMbDataLeft.getMbTCoeffs().getCoeffCount( cIdxL );
        }
    }

    const MbData& rcMbDataAbove = xGetBlockAbove( cIdx );
    if( xIsAvailable( rcMbDataAbove ) )
    {
        uiCoeffCount += rcMbDataAbove.getMbTCoeffs().getCoeffCount( cIdx );

        if( bLeftAvailable )
        {
            uiCoeffCount  += 1;
            uiCoeffCount >>= 1;
        }
    }

    if( 4 > uiCoeffCount )
    {
        uiCoeffCount >>= 1;
    }
    else
    {
        uiCoeffCount = ( 8 > uiCoeffCount) ? 2 : 3;
    }

    return uiCoeffCount;
}


__inline UInt MbDataAccess::getCtxCoeffCount( ChromaIdx cIdx )  const
{
    Bool bLeftAvailable = false;
    UInt uiCoeffCount     = 0;

    B4x4Idx       cLumIdx( m_aucChroma2LumaIdx[ cIdx ] );
    Int           iComp = ( cIdx >> 2) << 2;

    {
        B4x4Idx cLumIdxL = cLumIdx;
        const MbData& rcMbDataLeft = xGetBlockLeft( cLumIdxL );

        if( xIsAvailable( rcMbDataLeft ) )
        {
            bLeftAvailable = true;
            uiCoeffCount = rcMbDataLeft.getMbTCoeffs().getCoeffCount( CIdx( iComp + m_auc4x4Idx28x8Idx[ cLumIdxL.b4x4() ] ) );
        }
    }

    const MbData& rcMbDataAbove = xGetBlockAbove( cLumIdx );
    if( xIsAvailable( rcMbDataAbove ) )
    {
        uiCoeffCount += rcMbDataAbove.getMbTCoeffs().getCoeffCount( CIdx( iComp + m_auc4x4Idx28x8Idx[ cLumIdx.b4x4() ] ) );
        if( bLeftAvailable )
        {
            uiCoeffCount  += 1;
            uiCoeffCount >>= 1;
        }
    }

    if( 4 > uiCoeffCount )
    {
        uiCoeffCount >>= 1;
    }
    else
    {
        uiCoeffCount = ( 8 > uiCoeffCount) ? 2 : 3;
    }

    return uiCoeffCount;
}


__inline UInt MbDataAccess::getCtxChromaPredMode() const
{
    UInt uiCtx;

    uiCtx  = ((xGetMbLeft ().getChromaPredMode() > 0) ? 1 : 0);
    uiCtx += ((xGetMbAbove().getChromaPredMode() > 0) ? 1 : 0);

    return uiCtx;
}


__inline Int MbDataAccess::mostProbableIntraPredMode( LumaIdx cIdx )
{
    B4x4Idx cIdxL( cIdx.b4x4() );
    B4x4Idx cIdxA( cIdx.b4x4() );

    const MbData& rcMbDataLeft = xGetBlockLeft( cIdxL );
    Int iLeftPredMode  = ( xIsAvailableIntra( rcMbDataLeft ) ? rcMbDataLeft.intraPredMode( cIdxL ) : OUTSIDE);

    const MbData& rcMbDataAbove = xGetBlockAbove( cIdxA );
    Int iAbovePredMode = ( xIsAvailableIntra( rcMbDataAbove ) ? rcMbDataAbove.intraPredMode( cIdxA ) : OUTSIDE);

    Int iMostProbable = min( iLeftPredMode, iAbovePredMode );

    return ( OUTSIDE == iMostProbable ) ? DC_PRED : iMostProbable;
}

__inline Int MbDataAccess::encodeIntraPredMode( LumaIdx cIdx )
{
    const Int iMostProbable   = mostProbableIntraPredMode( cIdx );
    const Int iIntraPredMode  = m_rcMbCurr.intraPredMode ( cIdx );

    ROTRS( iMostProbable == iIntraPredMode, -1 )

        return (iIntraPredMode < iMostProbable) ? iIntraPredMode : iIntraPredMode-1;
}

__inline Int MbDataAccess::decodeIntraPredMode( LumaIdx cIdx )
{
    const Int iMostProbable   = mostProbableIntraPredMode( cIdx );
    const Int iIntraPredMode  = m_rcMbCurr.intraPredMode ( cIdx );

    ROTRS( -1 == iIntraPredMode, iMostProbable )

        return (iIntraPredMode < iMostProbable) ? iIntraPredMode : iIntraPredMode+1;
}

#ifdef   LF_INTERLACE
__inline UInt MbDataAccess::getCtxFieldFlag()  const
{
    UInt uiCtx = (m_rcMbLeft.getFieldFlag() ? 1: 0);
    if( m_bMbAff && ! isTopMb() )
    {
        uiCtx += (m_rcMbAboveAbove.getFieldFlag() ? 1: 0);
    }
    else
    {
        uiCtx += (m_rcMbAbove.getFieldFlag() ? 1: 0);
    }
    return uiCtx;
}
#endif //LF_INTERLACE

__inline UInt MbDataAccess::getCtxMbType() const
{
    const MbData& rcMbLeft   = xGetMbLeft ();
    const MbData& rcMbAbove  = xGetMbAbove();
    Bool bSkippedLeft  = ( !rcMbLeft .getBLSkipFlag() && rcMbLeft .isSkiped() );
    Bool bSkippedAbove = ( !rcMbAbove.getBLSkipFlag() && rcMbAbove.isSkiped() );
    UInt uiCtx         = ( bSkippedLeft  ? 0 : 1 );
    uiCtx             += ( bSkippedAbove ? 0 : 1 );
    return uiCtx;
}


__inline UInt MbDataAccess::getCtx8x8Flag() const
{
    UInt uiCtx = ( xGetMbLeft ().isTransformSize8x8() ? 1 : 0);
    uiCtx     += ( xGetMbAbove().isTransformSize8x8() ? 1 : 0);
    return uiCtx;
}


__inline UInt MbDataAccess::getCtxMbSkipped() const
{
#ifdef   LF_INTERLACE
    Bool bFieldFlag = m_rcMbCurr.getFieldFlag();

    if( m_bMbAff && ( isTopMb() || m_rcMbComplementary.getSkipFlag()  ) )
    {
        m_rcMbCurr.setFieldFlag( getDefaultFieldFlag() );
    }

    const MbData& rcMbDataLeft   = xGetMbLeft();
    const MbData& rcMbDataAbove   = xGetMbAbove();

    UInt uiCtx = (( rcMbDataLeft .getSkipFlag()) ? 0 : 1);
    uiCtx     += (( rcMbDataAbove.getSkipFlag()) ? 0 : 1);


    m_rcMbCurr.setFieldFlag( bFieldFlag );
    return uiCtx;
#else //!LF_INTERLACE
    return getCtxMbType();
#endif //LF_INTERLACE
}


__inline UInt MbDataAccess::getCtxBLSkipFlag() const
{
    const MbData& rcMbDataLeft  = xGetMbLeft  ();
    const MbData& rcMbDataAbove = xGetMbAbove ();

    UInt  uiCtx  = ( rcMbDataLeft .getBLSkipFlag() ? 0 : 1 );
    uiCtx       += ( rcMbDataAbove.getBLSkipFlag() ? 0 : 1 );

    return uiCtx;
}


__inline UInt MbDataAccess::getCtxBLQRefFlag() const
{
    const MbData& rcMbDataLeft  = xGetMbLeft  ();
    const MbData& rcMbDataAbove = xGetMbAbove ();

    UInt  uiCtx  = ( rcMbDataLeft .getBLQRefFlag() ? 0 : 1 );
    uiCtx       += ( rcMbDataAbove.getBLQRefFlag() ? 0 : 1 );

    return uiCtx;
}


__inline UInt MbDataAccess::getCtxDirectMbWoCoeff() const
{
    const MbData& rcMbDataLeft   = xGetMbLeft();
    const MbData& rcMbDataAbove  = xGetMbAbove();

    UInt uiCtx = (( rcMbDataLeft .getSkipFlag()) ? 0 : 1);
    uiCtx     += (( rcMbDataAbove.getSkipFlag()) ? 0 : 1);

    return uiCtx;
}

__inline UInt MbDataAccess::getCtxMbIntra4x4() const
{
    const MbData& rcMbDataLeft  = xGetMbLeft();
    const MbData& rcMbDataAbove = xGetMbAbove();
    Bool bIntraLeft  = ( !xIsAvailable( rcMbDataLeft  ) || ( !rcMbDataLeft .getBLSkipFlag() && rcMbDataLeft .isIntra4x4() ) );
    Bool bIntraAbove = ( !xIsAvailable( rcMbDataAbove ) || ( !rcMbDataAbove.getBLSkipFlag() && rcMbDataAbove.isIntra4x4() ) );
    UInt uiCtx       = ( bIntraLeft  ? 0 : 1 );
    uiCtx           += ( bIntraAbove ? 0 : 1 );
    return uiCtx;
}

__inline UInt MbDataAccess::getCtxRefIdx( ListIdx eLstIdx, ParIdx8x8 eParIdx ) const
{
    UInt uiCtx;

    uiCtx  = xGetRefIdxAbove( eLstIdx, eParIdx ) > 1 ? 2 : 0;
    uiCtx += xGetRefIdxLeft ( eLstIdx, eParIdx ) > 1 ? 1 : 0;

    return uiCtx;
}


__inline UInt MbDataAccess::getCtxMotPredFlag( ListIdx eLstIdx, ParIdx8x8 eParIdx ) const
{
    UInt uiCtx;

    uiCtx  = ( xGetMotPredFlagAbove( eLstIdx, eParIdx ) ? 2 : 0 );
    uiCtx += ( xGetMotPredFlagLeft ( eLstIdx, eParIdx ) ? 1 : 0 );

    return uiCtx;
}



__inline UInt MbDataAccess::getLeftLumaCbp( LumaIdx cIdx )  const
{
    const MbData& rcMbData = xGetBlockLeft( cIdx );

    if( ! xIsAvailable( rcMbData ) )
    {
        return 1;
    }
  if( !rcMbData.getBLSkipFlag() && rcMbData.isIntra16x16() )
    {
        return rcMbData.isAcCoded() ? 1 : 0;
    }
    return ( rcMbData.getMbCbp() >> m_auc4x4Idx28x8Idx[ cIdx.b4x4() ] ) & 1;
}

__inline UInt MbDataAccess::getAboveLumaCbp( LumaIdx cIdx )  const
{
    const MbData& rcMbData = xGetBlockAbove( cIdx );

    if( ! xIsAvailable( rcMbData ) )
    {
        return 1;
    }
    if( !rcMbData.getBLSkipFlag() && rcMbData.isIntra16x16() )
    {
        return rcMbData.isAcCoded() ? 1 : 0;
    }
    return ( rcMbData.getMbCbp() >> m_auc4x4Idx28x8Idx[ cIdx.b4x4() ] ) & 1;
}

__inline UInt MbDataAccess::getLeftChromaCbp()  const
{
    const MbData& rcMbData = xGetMbLeft();

    if( !rcMbData.getBLSkipFlag()  && rcMbData.isIntra16x16() )
    {
        return rcMbData.getCbpChroma16x16();
    }
    return rcMbData.getMbCbp() >> 4;
}

__inline UInt MbDataAccess::getAboveChromaCbp()  const
{
    const MbData& rcMbData = xGetMbAbove();

  if( !rcMbData.getBLSkipFlag() && rcMbData.isIntra16x16() )
    {
        return rcMbData.getCbpChroma16x16();
    }
    return rcMbData.getMbCbp() >> 4;
}


__inline UInt MbDataAccess::getAutoCbp() const
{
    UInt  uiCbp = m_rcMbCurr.getMbCbp();

    if( m_rcMbCurr.isIntra16x16() )
    {
        uiCbp  = ( m_rcMbCurr.isAcCoded() ? 15 : 0 ); //luma
        uiCbp += ( m_rcMbCurr.getCbpChroma16x16() << 4 ); //chroma
    }

    return uiCbp;
}

__inline UInt MbDataAccess::getLeftLumaCbpFGS( LumaIdx cIdx )  const
{
    const MbData& rcMbData = xGetBlockLeft( cIdx );

    if( ! xIsAvailable( rcMbData ) )
    {
        return 1;
    }
    return ( rcMbData.getMbCbp() >> m_auc4x4Idx28x8Idx[ cIdx.b4x4() ] ) & 1;
}

__inline UInt MbDataAccess::getAboveLumaCbpFGS( LumaIdx cIdx )  const
{
    const MbData& rcMbData = xGetBlockAbove( cIdx );

    if( ! xIsAvailable( rcMbData ) )
    {
        return 1;
    }
    return ( rcMbData.getMbCbp() >> m_auc4x4Idx28x8Idx[ cIdx.b4x4() ] ) & 1;
}

__inline UInt MbDataAccess::getLeftChromaCbpFGS()  const
{
    const MbData& rcMbData = xGetMbLeft();

    return rcMbData.getMbCbp() >> 4;
}

__inline UInt MbDataAccess::getAboveChromaCbpFGS()  const
{
    const MbData& rcMbData = xGetMbAbove();

    return rcMbData.getMbCbp() >> 4;
}


__inline UInt MbDataAccess::xGetLeftCodedBlockBit( UInt uiBit )  const
{
    AOT_DBG( uiBit > 30 );
    if( uiBit > 26 )
    {
        B4x4Idx       cIdx( m_aucChroma2LumaIdx[ uiBit - 27 ] );
        const MbData& rcMbData  = xGetBlockLeft( cIdx );
        if( ! xIsAvailable( rcMbData ) )
        {
      return ( !m_rcMbCurr.getBLSkipFlag() && m_rcMbCurr.isIntra() ? 1 : 0 );
        }
        return rcMbData.getBCBP( m_auc4x4Idx28x8Idx[ cIdx.b4x4() ] + 27 );
    }

    if( uiBit >= 24 ) // macroblock based stuff
    {
        const MbData& rcMbData = xGetMbLeft();
        if( ! xIsAvailable( rcMbData ) )
        {
      return ( !m_rcMbCurr.getBLSkipFlag() && m_rcMbCurr.isIntra() ? 1 : 0 );
        }
        return rcMbData.getBCBP( uiBit );
    }

    if( uiBit < 16 ) // luma block based
    {
        B4x4Idx       cIdx( uiBit );
        const MbData& rcMbData = xGetBlockLeft( cIdx );
        if( ! xIsAvailable( rcMbData ) )
        {
      return ( !m_rcMbCurr.getBLSkipFlag() && m_rcMbCurr.isIntra() ? 1 : 0 );
        }
        return rcMbData.getBCBP( cIdx.b4x4() );
    }
    // chroma block based
    B4x4Idx       cIdx( m_aucChroma2LumaIdx[ uiBit - 16 ] );
    Int           iOffset   = ( uiBit >= 20 ? 20 : 16 );
    const MbData& rcMbData  = xGetBlockLeft( cIdx );
    if( ! xIsAvailable( rcMbData ) )
    {
    return ( !m_rcMbCurr.getBLSkipFlag() && m_rcMbCurr.isIntra() ? 1 : 0 );
    }
    return rcMbData.getBCBP( m_auc4x4Idx28x8Idx[ cIdx.b4x4() ] + iOffset );
}

__inline UInt MbDataAccess::xGetAboveCodedBlockBit( UInt uiBit )  const
{
    AOT_DBG( uiBit > 30 );
    if( uiBit > 26 )
    {
        B4x4Idx       cIdx( m_aucChroma2LumaIdx[ uiBit - 27 ] );
        const MbData& rcMbData  = xGetBlockAbove( cIdx );
        if( ! xIsAvailable( rcMbData ) )
        {
      return ( !m_rcMbCurr.getBLSkipFlag() && m_rcMbCurr.isIntra() ? 1 : 0 );
        }
        return rcMbData.getBCBP( m_auc4x4Idx28x8Idx[ cIdx.b4x4() ] + 27 );
    }

    if( uiBit >= 24 ) // macroblock based stuff
    {
        const MbData& rcMbData = xGetMbAbove();
        if( ! xIsAvailable( rcMbData ) )
        {
      return ( !m_rcMbCurr.getBLSkipFlag() && m_rcMbCurr.isIntra() ? 1 : 0 );
        }
        return rcMbData.getBCBP( uiBit );
    }
    if( uiBit < 16 ) // luma block based
    {
        B4x4Idx       cIdx( uiBit );
        const MbData& rcMbData = xGetBlockAbove( cIdx );
        if( ! xIsAvailable( rcMbData ) )
        {
      return ( !m_rcMbCurr.getBLSkipFlag() && m_rcMbCurr.isIntra() ? 1 : 0 );
        }
        return rcMbData.getBCBP( cIdx.b4x4() );
    }
    // chroma block based
    B4x4Idx       cIdx( m_aucChroma2LumaIdx[ uiBit - 16 ] );
    Int           iOffset   = ( uiBit >= 20 ? 20 : 16 );
    const MbData& rcMbData  = xGetBlockAbove( cIdx );
    if( ! xIsAvailable( rcMbData ) )
    {
    return ( !m_rcMbCurr.getBLSkipFlag() && m_rcMbCurr.isIntra() ? 1 : 0 );
    }
    return rcMbData.getBCBP( m_auc4x4Idx28x8Idx[ cIdx.b4x4() ] + iOffset );
}


__inline UInt MbDataAccess::getCtxCodedBlockBit( UInt uiBitPos ) const
{
    UInt uiCtx;
    uiCtx  = xGetLeftCodedBlockBit ( uiBitPos );
    uiCtx += xGetAboveCodedBlockBit( uiBitPos ) << 1;
    return uiCtx;
}


__inline Void MbDataAccess::xGetColocatedMvRefIdx( Mv& rcMv, SChar& rscRefIdx, LumaIdx cIdx ) const
{
    ListIdx         eListIdx         = LIST_0;

#ifdef   LF_INTERLACE
    MvRefConversion eMvRefConversion = ONE_TO_ONE;
    const MbData&   rcMbColocated    = xGetBlockColocated( cIdx, eMvRefConversion );
    if( ( rscRefIdx = rcMbColocated.getMbMotionData( eListIdx ).getRefIdx( cIdx ) ) <= BLOCK_NOT_AVAILABLE )
#else //!LF_INTERLACE
    if( ( rscRefIdx = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getRefIdx( cIdx ) ) < 1 )
#endif //LF_INTERLACE
    {
        eListIdx  = LIST_1;
#ifdef   LF_INTERLACE
        rscRefIdx = rcMbColocated.getMbMotionData( eListIdx ).getRefIdx( cIdx );
#else //!LF_INTERLACE
        rscRefIdx = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getRefIdx( cIdx );
#endif //LF_INTERLACE
    }
#ifdef   LF_INTERLACE_FIX
    if( rscRefIdx <= BLOCK_NOT_AVAILABLE )
#else //!LF_INTERLACE_FIX
    if( rscRefIdx < 1 )
#endif //LF_INTERLACE_FIX
    {
        rcMv = Mv::ZeroMv();
    }
    else
    {
#ifdef   LF_INTERLACE
        rcMv = rcMbColocated.getMbMotionData( eListIdx ).getMv( cIdx );
#else //!LF_INTERLACE
        rcMv = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getMv( cIdx );
#endif //LF_INTERLACE
    }
}



__inline Void MbDataAccess::xGetColocatedMvsRefIdxNonInterlaced( Mv acMv[], SChar& rscRefIdx, ParIdx8x8 eParIdx ) const
{
    ListIdx         eListIdx         = LIST_0;

#ifdef   LF_INTERLACE
    const MbData&   rcMbColocated    = xGetBlockColocatedNonInterlaced();
    if( ( rscRefIdx = rcMbColocated.getMbMotionData( eListIdx ).getRefIdx( eParIdx ) ) <= BLOCK_NOT_AVAILABLE )
#else //!LF_INTERLACE
    if( ( rscRefIdx = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getRefIdx( eParIdx ) ) < 1 )
#endif //LF_INTERLACE
    {
        eListIdx  = LIST_1;
#ifdef   LF_INTERLACE
        rscRefIdx = rcMbColocated.getMbMotionData( eListIdx ).getRefIdx( eParIdx );
#else //!LF_INTERLACE
        rscRefIdx = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getRefIdx( eParIdx );
#endif //LF_INTERLACE
    }
#ifdef   LF_INTERLACE_FIX
    if( rscRefIdx <= BLOCK_NOT_AVAILABLE )
#else //!LF_INTERLACE_FIX
    if( rscRefIdx < 1 )
#endif //LF_INTERLACE_FIX
    {
        acMv[0] = acMv[1] = acMv[2] = acMv[3] = Mv::ZeroMv();
    }
    else
    {
#ifdef   LF_INTERLACE
        acMv[0] = rcMbColocated.getMbMotionData( eListIdx ).getMv( eParIdx, SPART_4x4_0 );
        acMv[1] = rcMbColocated.getMbMotionData( eListIdx ).getMv( eParIdx, SPART_4x4_1 );
        acMv[2] = rcMbColocated.getMbMotionData( eListIdx ).getMv( eParIdx, SPART_4x4_2 );
        acMv[3] = rcMbColocated.getMbMotionData( eListIdx ).getMv( eParIdx, SPART_4x4_3 );
#else //!LF_INTERLACE
        acMv[0] = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getMv( eParIdx, SPART_4x4_0 );
        acMv[1] = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getMv( eParIdx, SPART_4x4_1 );
        acMv[2] = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getMv( eParIdx, SPART_4x4_2 );
        acMv[3] = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getMv( eParIdx, SPART_4x4_3 );
#endif //LF_INTERLACE_FIX
    }
}


__inline const RefPic& MbDataAccess::xGetColocatedMvRefPic( Mv& rcMv, SChar& rscRefIdx, LumaIdx cIdx ) const
{
    ListIdx         eListIdx         = LIST_0;

#ifdef   LF_INTERLACE
    MvRefConversion eMvRefConversion = ONE_TO_ONE;
    const MbData&   rcMbColocated    = xGetBlockColocated( cIdx, eMvRefConversion );
    if( ( rscRefIdx = rcMbColocated.getMbMotionData( eListIdx ).getRefIdx( cIdx ) ) <= BLOCK_NOT_AVAILABLE )
#else //!LF_INTERLACE
    if( ( rscRefIdx = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getRefIdx( cIdx ) ) < 1 )
#endif //LF_INTERLACE
    {
        eListIdx  = LIST_1;
#ifdef   LF_INTERLACE
        rscRefIdx = rcMbColocated.getMbMotionData( eListIdx ).getRefIdx( cIdx );
#else //!LF_INTERLACE
        rscRefIdx = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getRefIdx( cIdx );
#endif //LF_INTERLACE
    }
#ifdef   LF_INTERLACE_FIX
    if( rscRefIdx <= BLOCK_NOT_AVAILABLE )
#else //!LF_INTERLACE_FIX
    if( rscRefIdx < 1 )
#endif //LF_INTERLACE_FIX
    {
        rcMv = Mv::ZeroMv();
    }
    else
    {
#ifdef   LF_INTERLACE
        rcMv = rcMbColocated.getMbMotionData( eListIdx ).getMv( cIdx );
#else //!LF_INTERLACE
        rcMv = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getMv( cIdx );
#endif //LF_INTERLACE
    }

#ifdef  LF_INTERLACE
    //--- mv scaling ----
    if( eMvRefConversion == FRM_TO_FLD )
    {
        rcMv.setFrameToFieldPredictor();
    }
    else if( eMvRefConversion == FLD_TO_FRM )
    {
        rcMv.setFieldToFramePredictor();
    }
    return rcMbColocated.getMbMotionData( eListIdx ).getRefPic( cIdx );
#else //!LF_INTERLACE
    return m_rcMbColocated.getMbMotionDataBase( eListIdx ).getRefPic( cIdx );
#endif //LF_INTERLACE
}

__inline const RefPic& MbDataAccess::xGetColocatedMvsRefPicNonInterlaced( Mv acMv[], SChar& rscRefIdx, ParIdx8x8 eParIdx ) const
{
    ListIdx         eListIdx         = LIST_0;

#ifdef   LF_INTERLACE
    const MbData&   rcMbColocated    = xGetBlockColocatedNonInterlaced();
    if( ( rscRefIdx = rcMbColocated.getMbMotionData( eListIdx ).getRefIdx( eParIdx ) ) <= BLOCK_NOT_AVAILABLE )
#else //!LF_INTERLACE
    if( ( rscRefIdx = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getRefIdx( eParIdx ) ) < 1 )
#endif //LF_INTERLACE
    {
        eListIdx  = LIST_1;
#ifdef   LF_INTERLACE
        rscRefIdx = rcMbColocated.getMbMotionData( eListIdx ).getRefIdx( eParIdx );
#else //!LF_INTERLACE
        rscRefIdx = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getRefIdx( eParIdx );
#endif //LF_INTERLACE
    }
    if( rscRefIdx < 1 )
    {
        acMv[0] = acMv[1] = acMv[2] = acMv[3] = Mv::ZeroMv();
    }
    else
    {
#ifdef   LF_INTERLACE
        acMv[0] = rcMbColocated.getMbMotionData( eListIdx ).getMv( eParIdx, SPART_4x4_0 );
        acMv[1] = rcMbColocated.getMbMotionData( eListIdx ).getMv( eParIdx, SPART_4x4_1 );
        acMv[2] = rcMbColocated.getMbMotionData( eListIdx ).getMv( eParIdx, SPART_4x4_2 );
        acMv[3] = rcMbColocated.getMbMotionData( eListIdx ).getMv( eParIdx, SPART_4x4_3 );
#else //!LF_INTERLACE
        acMv[0] = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getMv( eParIdx, SPART_4x4_0 );
        acMv[1] = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getMv( eParIdx, SPART_4x4_1 );
        acMv[2] = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getMv( eParIdx, SPART_4x4_2 );
        acMv[3] = m_rcMbColocated.getMbMotionDataBase( eListIdx ).getMv( eParIdx, SPART_4x4_3 );
#endif //LF_INTERLACE
    }

#ifdef   LF_INTERLACE
    return rcMbColocated.getMbMotionData( eListIdx ).getRefPic( eParIdx );
#else //!LF_INTERLACE
    return m_rcMbColocated.getMbMotionDataBase( eListIdx ).getRefPic( eParIdx );
#endif //LF_INTERLACE
}


__inline const MbData& MbDataAccess::xGetMbLeft() const
{
#ifdef   LF_INTERLACE
    if( m_rcMbCurr.getFieldFlag() == m_rcMbLeft.getFieldFlag() ) // same frame/field mode
    {
        return m_rcMbLeft;
    }
    return ( isTopMb() ? m_rcMbLeft : m_rcMbAboveLeft );
#else //!LF_INTERLACE
    return m_rcMbLeft;
#endif //LF_INTERLACE
}

__inline const MbData& MbDataAccess::xGetMbAbove() const
{
#ifdef   LF_INTERLACE
    if( ! m_bMbAff )
    {
        return m_rcMbAbove;
    }

    if( ! m_rcMbCurr.getFieldFlag() || ( isTopMb() && ! m_rcMbAbove.getFieldFlag() ) )
    {
        return m_rcMbAbove;
    }
    return m_rcMbAboveAbove;
#else //!LF_INTERLACE
    return m_rcMbAbove;
#endif //LF_INTERLACE
}


__inline const MbData& MbDataAccess::xGetBlockLeft( LumaIdx& rcIdx ) const
{
    if( rcIdx.x() )  // inside current macroblock
    {
        rcIdx = rcIdx + CURR_MB_LEFT_NEIGHBOUR;
        return m_rcMbCurr;
    }
#ifdef   LF_INTERLACE
    if( ! m_bMbAff )
    {
        rcIdx = rcIdx + LEFT_MB_LEFT_NEIGHBOUR;
        return m_rcMbLeft;
    }

    if( m_rcMbCurr.getFieldFlag() == m_rcMbLeft.getFieldFlag() ) // same frame/field mode
    {
        rcIdx = rcIdx + LEFT_MB_LEFT_NEIGHBOUR;
        return m_rcMbLeft;
    }
    if( m_rcMbCurr.getFieldFlag() && ! m_rcMbLeft.getFieldFlag() ) // current field, neighbour frame
    {
        Int i4x4 = rcIdx.b4x4();
        rcIdx = B4x4Idx( i4x4 % 8 ? 11 : 3 );
        return ( i4x4 > 4 && isTopMb() ? m_rcMbBelowLeft : i4x4 <= 4 && ! isTopMb() ? m_rcMbAboveLeft : m_rcMbLeft );
    }
    // current frame, neighbour field
    if( isTopMb() )
    {
        rcIdx = B4x4Idx( rcIdx.b4x4() > 4 ?  7 :  3 );
        return m_rcMbLeft;
    }
    rcIdx = B4x4Idx( rcIdx.b4x4() > 4 ? 15 : 11 );
    return m_rcMbAboveLeft;
#else //!LF_INTERLACE
    rcIdx = rcIdx + LEFT_MB_LEFT_NEIGHBOUR;
    return m_rcMbLeft;
#endif //LF_INTERLACE
}

#ifdef   LF_INTERLACE
__inline const MbData& MbDataAccess::xGetBlockLeftBottom( LumaIdx& rcIdx ) const
{
    if( rcIdx.x() )  // inside current macroblock
    {
        rcIdx = rcIdx + CURR_MB_LEFT_NEIGHBOUR;
        return m_rcMbCurr;
    }

    if( ! m_bMbAff )
    {
        rcIdx = rcIdx + LEFT_MB_LEFT_NEIGHBOUR;
        return m_rcMbLeft;
    }

    if( m_rcMbCurr.getFieldFlag() == m_rcMbLeft.getFieldFlag() ) // same frame/field mode
    {
        rcIdx = rcIdx + LEFT_MB_LEFT_NEIGHBOUR;
        return m_rcMbLeft;
    }
    if( m_rcMbCurr.getFieldFlag() && ! m_rcMbLeft.getFieldFlag() ) // current field, neighbour frame
    {
        Int i4x4 = rcIdx.b4x4();
        rcIdx = B4x4Idx( i4x4 % 8 ? 15 : 7 );
        return ( i4x4 > 4 && isTopMb() ? m_rcMbBelowLeft : i4x4 <= 4 && ! isTopMb() ? m_rcMbAboveLeft : m_rcMbLeft );
    }
    // current frame, neighbour field
    if( isTopMb() )
    {
        rcIdx = B4x4Idx( rcIdx.b4x4() > 4 ?  7 :  3 );
        return m_rcMbBelowLeft;
    }
    rcIdx = B4x4Idx( rcIdx.b4x4() > 4 ? 15 : 11 );
    return m_rcMbLeft;
}
#endif //LF_INTERLACE

__inline const MbData& MbDataAccess::xGetBlockAbove( LumaIdx& rcIdx ) const
{
    if( rcIdx.y() ) // inside current macroblock
    {
        rcIdx = rcIdx + CURR_MB_ABOVE_NEIGHBOUR;
        return m_rcMbCurr;
    }
    // outside current macroblock
    rcIdx = rcIdx + ABOVE_MB_ABOVE_NEIGHBOUR;
#ifdef   LF_INTERLACE
    if( ! m_bMbAff )
    {
        return m_rcMbAbove;
    }

    if( ! m_rcMbCurr.getFieldFlag() || ( isTopMb() && ! m_rcMbAbove.getFieldFlag() ) )
    {
        return m_rcMbAbove;
    }
    return m_rcMbAboveAbove;
#else //!LF_INTERLACE
    return m_rcMbAbove;
#endif //LF_INTERLACE
}


__inline const MbData& MbDataAccess::xGetBlockAboveLeft( LumaIdx& cIdx ) const
{
    if( cIdx.x() )
    {
        if( cIdx.y() ) // inside current macroblock
        {
            cIdx = cIdx + CURR_MB_ABOVE_NEIGHBOUR + CURR_MB_LEFT_NEIGHBOUR;
            return m_rcMbCurr;
        }
        // inside above macroblock
#ifdef   LF_INTERLACE
        cIdx = cIdx + CURR_MB_LEFT_NEIGHBOUR;
        return xGetBlockAbove( cIdx );
#else //!LF_INTERLACE
        cIdx = cIdx + ABOVE_MB_ABOVE_NEIGHBOUR + CURR_MB_LEFT_NEIGHBOUR;
        return m_rcMbAbove;
#endif //LF_INTERLACE
    }
    if( cIdx.y() ) // inside left macroblock
    {
#ifdef   LF_INTERLACE
        cIdx = cIdx + CURR_MB_ABOVE_NEIGHBOUR;
        return xGetBlockLeftBottom( cIdx );
#else //!LF_INTERLACE
        cIdx = cIdx + CURR_MB_ABOVE_NEIGHBOUR + LEFT_MB_LEFT_NEIGHBOUR;
        return m_rcMbLeft;
#endif //LF_INTERLACE
    }
    // inside above left macroblock
#ifdef   LF_INTERLACE
    cIdx = B4x4Idx( ! m_rcMbCurr.getFieldFlag() && ! isTopMb() && m_rcMbAboveLeft.getFieldFlag() ? 7 : 15 );

    if( ! m_rcMbCurr.getFieldFlag() && ! isTopMb() && m_rcMbAboveLeft.getFieldFlag() )
    {
        return m_rcMbLeft;
    }
    if( ! m_rcMbCurr.getFieldFlag() || ( isTopMb() && ! m_rcMbAboveLeft.getFieldFlag() ) )
    {
        return m_rcMbAboveLeft;
    }
    return m_rcMbAboveAboveLeft;
#else //!LF_INTERLACE
    cIdx = B4x4Idx( 15 );
    return m_rcMbAboveLeft;
#endif //LF_INTERLACE
}

__inline const MbData& MbDataAccess::xGetBlockAboveRight( LumaIdx& cIdx ) const
{
    if( cIdx.x() < 3 )
    {
        if( cIdx.y() ) // inside current macroblock
        {
            cIdx = cIdx + CURR_MB_ABOVE_NEIGHBOUR + CURR_MB_RIGHT_NEIGHBOUR;

            if( cIdx.b4x4() == 2 || cIdx.b4x4() == 10 )
            {
                return m_rcMbUnavailable;
            }
            return m_rcMbCurr;
        }
        // inside above macroblock pair
#ifdef   LF_INTERLACE
        cIdx = cIdx + CURR_MB_RIGHT_NEIGHBOUR;
        return xGetBlockAbove( cIdx );
#else //!LF_INTERLACE
        cIdx = cIdx + ABOVE_MB_ABOVE_NEIGHBOUR + CURR_MB_RIGHT_NEIGHBOUR;
        return m_rcMbAbove;
#endif //LF_INTERLACE
    }
#ifdef   LF_INTERLACE
    if( cIdx.y() || ( ! m_rcMbCurr.getFieldFlag() && ! isTopMb() ) ) // not available ( inside right mb or inside above right macroblock for a bottom macroblock )
    {
        cIdx = cIdx + RIGHT_MB_RIGHT_NEIGHBOUR;
        return m_rcMbUnavailable;
    }
    // inside above rigth macroblock pair
    cIdx = B4x4Idx( 12 );
    if( ! m_rcMbCurr.getFieldFlag() || ( isTopMb() && ! m_rcMbAboveRight.getFieldFlag() ) )
    {
        return m_rcMbAboveRight;
    }
    return m_rcMbAboveAboveRight;
#else //!LF_INTERLACE
    if( cIdx.y() )
    {
        cIdx = cIdx + CURR_MB_ABOVE_NEIGHBOUR + RIGHT_MB_RIGHT_NEIGHBOUR;
        return m_rcMbUnavailable;
    }
    // inside above rigth macroblock pair
    cIdx = B4x4Idx( 12 );
    return m_rcMbAboveRight;
#endif //LF_INTERLACE
}

#ifdef   LF_INTERLACE
__inline const MbData& MbDataAccess::xGetBlockColocated( LumaIdx& rcIdx, MvRefConversion& eMvRefConversion ) const
{
    Bool bCurrField = getSH().getFieldPicFlag() || m_rcMbCurr.        getFieldFlag();
    Bool bColField  = m_bColocatedField         || m_rcMbColocatedTop.getFieldFlag();

    if( bCurrField == bColField )
    {
        eMvRefConversion = ONE_TO_ONE;
        return ( m_bIsTopRowMb ? m_rcMbColocatedTop : m_rcMbColocatedBot );
    }

    if( bCurrField )
    {
        eMvRefConversion    = FRM_TO_FLD;
        const MbData& rcCol = ( rcIdx.b4x4() < 8 ? m_rcMbColocatedTop : m_rcMbColocatedBot );
        rcIdx               = B4x4Idx( rcIdx.x() + 4 * ( ( 2 * rcIdx.y() ) % 4 ) );
        return rcCol;
    }

    eMvRefConversion  = FLD_TO_FRM;
    rcIdx             = B4x4Idx( rcIdx.x() + 4 * ( rcIdx.y() / 2 ) + ( m_bIsTopRowMb ? 0 : 8 ) );
    return ( m_bUseTopField ? m_rcMbColocatedTop : m_rcMbColocatedBot );
}

__inline const MbData& MbDataAccess::xGetBlockColocatedNonInterlaced() const
{
    return ( m_bIsTopRowMb ? m_rcMbColocatedTop : m_rcMbColocatedBot );
}
#endif //LF_INTERLACE

H264AVC_NAMESPACE_END


#endif // !defined(AFX_MBDATAACCESS_H__710205A4_CFE9_496D_A469_C47EC8D2FBD2__INCLUDED_)
